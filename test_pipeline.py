import json
import tempfile
import os
from pathlib import Path
import pytest
from unittest.mock import MagicMock, patch

from state_manager import StateManager
from leetcode_client import LeetCodeClient
from editorial_generator import SolutionOutput, clean_html_to_markdown
from git_sync import (
    get_problem_folder_name,
    save_problem_files,
    generate_root_readme,
    build_difficulty_badge,
)
from config import LC_PUBLISH_DELAY_MIN, LC_PUBLISH_DELAY_MAX


class TestAntiBanGuardrails:
    """
    Tests specifically designed to prevent LeetCode shadowbans, rate limit triggers,
    and duplicate spamming.
    """

    def test_rate_limit_error_handling(self):
        """
        Verify that LeetCode's rate-limit messages are cleanly detected and raised,
        preventing blind retries that could trigger account bans.
        """
        client = LeetCodeClient("dummy_session", "dummy_csrf", "test_user")

        # Mock a GraphQL response returning the rate-limit warning
        mock_response = MagicMock()
        mock_response.status_code = 200
        mock_response.json.return_value = {
            "errors": [{"message": "You are posting too frequently. Please try again in 60 seconds."}]
        }

        with patch.object(client.session, "post", return_value=mock_response):
            with pytest.raises(RuntimeError, match="Rate limited by LeetCode"):
                client.publish_solution("two-sum", "Title", "Content", ["c", "array"])

    def test_cooldown_anti_ban_range(self):
        """
        LeetCode enforces a 60s cooldown on community posts.
        Ensure our configured jitter delay is safely above 60 seconds.
        """
        assert LC_PUBLISH_DELAY_MIN >= 60, "LC_PUBLISH_DELAY_MIN must be >= 60s to prevent LeetCode shadowbans"
        assert LC_PUBLISH_DELAY_MAX > LC_PUBLISH_DELAY_MIN, "LC_PUBLISH_DELAY_MAX must exceed min delay for jitter"

    def test_tag_slug_c_enforced(self):
        """
        LeetCode requires 'c' as the internal tag slug for C++ solutions.
        Verify that publish_solution always injects 'c' if omitted.
        """
        client = LeetCodeClient("dummy_session", "dummy_csrf", "test_user")
        mock_response = MagicMock()
        mock_response.status_code = 200
        mock_response.json.return_value = {
            "data": {
                "ugcArticlePublishSolution": {
                    "article": {"uuid": "test-uuid-123", "title": "Test", "slug": "test-slug"}
                }
            }
        }

        with patch.object(client.session, "post", return_value=mock_response) as mock_post:
            client.publish_solution("two-sum", "Test Title", "Content", ["array", "hash-table"])
            sent_payload = mock_post.call_args[1]["json"]
            tags_sent = sent_payload["variables"]["data"]["tags"]
            assert "c" in tags_sent, "Tag 'c' must always be sent in LeetCode solution mutation"

    def test_existing_solution_detection_prevents_duplicate_post(self):
        """
        Verify that has_user_posted_solution accurately identifies if the user
        already authored a post to prevent duplicate posting penalties.
        """
        client = LeetCodeClient("dummy_session", "dummy_csrf", "adityakumar")

        # Mock ugcArticleUserSolutionArticles returning articles
        mock_response = MagicMock()
        mock_response.status_code = 200
        mock_response.json.return_value = {
            "data": {
                "ugcArticleUserSolutionArticles": {
                    "totalNum": 1,
                    "edges": [
                        {
                            "node": {
                                "uuid": "test-uuid-1",
                                "title": "Two Sum Clean Solution",
                                "slug": "two-sum-clean-solution",
                                "questionSlug": "two-sum",
                                "questionTitle": "Two Sum",
                            }
                        }
                    ],
                }
            }
        }

        with patch.object(client.session, "post", return_value=mock_response):
            assert client.has_user_posted_solution("two-sum") is True
            assert client.has_user_posted_solution("unknown-problem") is False


class TestStateManager:
    """
    Tests state tracking and deduplication to avoid redundant queries and re-runs.
    """

    def test_state_persistence_and_deduplication(self):
        with tempfile.NamedTemporaryFile(suffix=".json", delete=False) as tmp:
            tmp_path = Path(tmp.name)

        try:
            state = StateManager(state_file_path=tmp_path)
            assert state.is_processed("dummy-unindexed-problem") is False

            state.record_synced(
                slug="dummy-unindexed-problem",
                frontend_id="9999",
                title="Dummy Problem",
                difficulty="Easy",
                submission_id=123456,
                folder_path="9999-dummy-unindexed-problem",
                lc_published=True,
                lc_article_uuid="uuid-1",
                lc_post_slug="dummy-editorial",
                tags=["c", "array"],
            )

            # Reload from disk
            new_state = StateManager(state_file_path=tmp_path)
            assert new_state.is_processed("dummy-unindexed-problem") is True
            assert new_state.is_processed("9999") is True
            assert new_state.is_processed("non-existent") is False

            prob = new_state.get_problem("dummy-unindexed-problem")
            assert prob is not None
            assert prob["frontend_id"] == "9999"
            assert prob["lc_published"] is True
        finally:
            if tmp_path.exists():
                tmp_path.unlink()


class TestEditorialQualityAndSchema:
    """
    Tests structured schema validation, canonical LeetCode sections, and HTML cleaning.
    """

    def test_solution_output_schema_validation(self):
        valid_data = {
            "lc_post_title": "Beats 100% | O(N) Hash Table | C++20 Clean Solution",
            "lc_post_markdown": "# Intuition\nCore insight.\n\n# Approach\n1. Step one\n\n# Complexity\n- Time: $$O(N)$$\n\n# Code\n```cpp []\nclass Solution {};\n```",
            "selected_tag_slugs": ["c", "hash-table", "array"],
            "github_cpp_file": "// Problem: Two Sum\n#include <bits/stdc++.h>\nusing namespace std;\nclass Solution {};",
            "github_readme_markdown": "# [1. Two Sum](https://leetcode.com/problems/two-sum/)\n## Problem Description\n...",
        }
        obj = SolutionOutput.model_validate(valid_data)
        assert obj.lc_post_title.startswith("Beats")
        assert "# Intuition" in obj.lc_post_markdown
        assert "# Approach" in obj.lc_post_markdown
        assert "# Complexity" in obj.lc_post_markdown
        assert "# Code" in obj.lc_post_markdown
        assert "c" in obj.selected_tag_slugs

    def test_clean_html_to_markdown(self):
        raw_html = "<p>Given an array of integers <code>nums</code>.</p><strong>Example 1:</strong><ul><li>Item 1</li></ul>"
        md = clean_html_to_markdown(raw_html)
        assert "<p>" not in md
        assert "<code>" not in md
        assert "nums" in md
        assert "Example 1:" in md


class TestGitSyncAndTOC:
    """
    Tests folder zero-padding, file persistence, and root README generation.
    """

    def test_problem_folder_zero_padding(self):
        assert get_problem_folder_name("1", "two-sum") == "0001-two-sum"
        assert get_problem_folder_name(42, "trapping-rain-water") == "0042-trapping-rain-water"
        assert get_problem_folder_name("146", "lru-cache") == "0146-lru-cache"
        assert get_problem_folder_name("1024", "video-stitching") == "1024-video-stitching"

    def test_difficulty_badges(self):
        assert "`Easy`" in build_difficulty_badge("Easy")
        assert "`Medium`" in build_difficulty_badge("Medium")
        assert "`Hard`" in build_difficulty_badge("Hard")

    def test_root_readme_generation(self):
        with tempfile.TemporaryDirectory() as tmpdir:
            from unittest.mock import patch
            with patch("git_sync.REPO_PATH", Path(tmpdir)):
                problems = [
                    {
                        "frontend_id": "1",
                        "slug": "two-sum",
                        "title": "Two Sum",
                        "difficulty": "Easy",
                        "folder_path": "0001-two-sum",
                        "lc_published": True,
                        "lc_post_slug": "two-sum-clean-hash-map",
                        "tags": ["array", "hash-table"],
                    }
                ]
                readme_path = generate_root_readme(problems, auto_commit=False)
                content = readme_path.read_text(encoding="utf-8")

                assert "Total Solved" in content
                assert "0001" in content
                assert "Two Sum" in content
                assert "`Easy`" in content
                assert "two-sum-clean-hash-map" in content
