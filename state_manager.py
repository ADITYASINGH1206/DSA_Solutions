import json
import os
import tempfile
from datetime import datetime, timezone
from pathlib import Path
from typing import Dict, Any, Optional, List, Tuple
from config import STATE_FILE


class StateManager:
    """
    Manages the local state.json file to track processed LeetCode problems,
    prevent duplicate LLM generations, and avoid duplicate LeetCode solution publications.
    """

    def __init__(self, state_file_path: Path = STATE_FILE):
        self.state_file_path = Path(state_file_path)
        self.data: Dict[str, Any] = {
            "version": 1,
            "last_synced_at": None,
            "synced_problems": {},
        }
        self.load()

    def load(self) -> None:
        if self.state_file_path.exists():
            try:
                with open(self.state_file_path, "r", encoding="utf-8") as f:
                    self.data = json.load(f)
                if "synced_problems" not in self.data:
                    self.data["synced_problems"] = {}
            except Exception as e:
                print(f"[!] Warning: Failed to read state file ({e}). Starting with clean state.")

    def save(self) -> None:
        """
        Atomically saves state using a temporary file to avoid corruption.
        """
        self.data["last_synced_at"] = datetime.now(timezone.utc).isoformat()
        self.state_file_path.parent.mkdir(parents=True, exist_ok=True)

        temp_fd, temp_path = tempfile.mkstemp(
            dir=self.state_file_path.parent, prefix="state_", suffix=".tmp"
        )
        try:
            with os.fdopen(temp_fd, "w", encoding="utf-8") as f:
                json.dump(self.data, f, indent=2, ensure_ascii=False)
            os.replace(temp_path, self.state_file_path)
        except Exception:
            if os.path.exists(temp_path):
                os.remove(temp_path)
            raise

    def _scan_repo_problems(self) -> Tuple[set, set]:
        """
        Scan the Solutions directory for any pre-existing problem solutions
        (e.g., '1.Two Sum', '0001-two-sum', 'Solutions/0000-0099/2. Add Two Numbers').
        Results (both numeric IDs and normalized slugs) are cached in memory for high performance.
        """
        if hasattr(self, "_cached_repo_ids") and self._cached_repo_ids is not None:
            return self._cached_repo_ids, self._cached_repo_slugs

        from config import SOLUTIONS_DIR
        found_ids = set()
        found_slugs = set()
        if not SOLUTIONS_DIR.exists():
            self._cached_repo_ids = found_ids
            self._cached_repo_slugs = found_slugs
            return found_ids, found_slugs

        import re
        for p in SOLUTIONS_DIR.glob("**/*"):
            if p.is_dir():
                # Ignore century range folder names like 0000-0099
                if re.match(r"^\d{4}-\d{4}$", p.name):
                    continue
                m = re.match(r"^(\d+)[.\s-]+(.*)$", p.name)
                if m:
                    try:
                        found_ids.add(int(m.group(1)))
                    except ValueError:
                        pass
                    slug_part = re.sub(r"[^a-z0-9]+", "-", m.group(2).lower()).strip("-")
                    if slug_part:
                        found_slugs.add(slug_part)

        self._cached_repo_ids = found_ids
        self._cached_repo_slugs = found_slugs
        return found_ids, found_slugs

    def is_processed(self, slug_or_id: str) -> bool:
        """
        Check if a problem has already been processed in state.json OR
        already exists in the repository's Solutions/ directory (by ID or slug).
        """
        key = str(slug_or_id).lower().strip()
        if key in self.data["synced_problems"]:
            return True
        for item in self.data["synced_problems"].values():
            if str(item.get("frontend_id")) == key or item.get("slug") == key:
                return True

        # Check repository filesystem for matching ID or slug
        found_ids, found_slugs = self._scan_repo_problems()
        if key in found_slugs:
            return True

        try:
            numeric_id = int(slug_or_id)
            if numeric_id in found_ids:
                return True
        except ValueError:
            pass

        return False

    def get_problem(self, slug_or_id: str) -> Optional[Dict[str, Any]]:
        key = str(slug_or_id).lower()
        if key in self.data["synced_problems"]:
            return self.data["synced_problems"][key]
        for item in self.data["synced_problems"].values():
            if str(item.get("frontend_id")) == str(slug_or_id) or item.get("slug") == key:
                return item
        return None

    def record_synced(
        self,
        slug: str,
        frontend_id: str,
        title: str,
        difficulty: str,
        submission_id: int,
        folder_path: str,
        lc_published: bool,
        lc_article_uuid: Optional[str] = None,
        lc_post_slug: Optional[str] = None,
        tags: Optional[List[str]] = None,
    ) -> None:
        self.data["synced_problems"][slug] = {
            "frontend_id": str(frontend_id),
            "slug": slug,
            "title": title,
            "difficulty": difficulty,
            "submission_id": int(submission_id),
            "folder_path": folder_path,
            "lc_published": lc_published,
            "lc_article_uuid": lc_article_uuid,
            "lc_post_slug": lc_post_slug,
            "tags": tags or [],
            "git_committed": True,
            "synced_at": datetime.now(timezone.utc).isoformat(),
        }
        self.save()

    def get_all_synced_problems(self) -> List[Dict[str, Any]]:
        problems = list(self.data["synced_problems"].values())
        # Sort by frontend_id numeric
        def get_sort_key(p):
            fid = p.get("frontend_id", "0")
            try:
                return int(fid)
            except ValueError:
                return 999999
        problems.sort(key=get_sort_key)
        return problems

    def get_summary(self) -> Dict[str, Any]:
        problems = self.get_all_synced_problems()
        by_diff = {"Easy": 0, "Medium": 0, "Hard": 0, "Other": 0}
        lc_pub_count = 0
        for p in problems:
            diff = p.get("difficulty", "Other")
            by_diff[diff] = by_diff.get(diff, 0) + 1
            if p.get("lc_published"):
                lc_pub_count += 1

        return {
            "total_synced": len(problems),
            "lc_published": lc_pub_count,
            "difficulties": by_diff,
            "last_synced_at": self.data.get("last_synced_at"),
        }
