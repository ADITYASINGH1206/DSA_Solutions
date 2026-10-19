import os
import subprocess
from pathlib import Path
from typing import List, Dict, Any, Optional

from config import REPO_PATH
from editorial_generator import SolutionOutput


def ensure_git_repo():
    """
    Ensure the REPO_PATH is initialized as a git repository.
    """
    git_dir = REPO_PATH / ".git"
    if not git_dir.exists():
        subprocess.run(["git", "-C", str(REPO_PATH), "init", "-b", "main"], check=True)


def get_problem_folder_name(frontend_id: Any, slug: str) -> str:
    """
    Format folder as 0001-two-sum (zero-padded 4-digit ID).
    """
    try:
        numeric_id = int(frontend_id)
        return f"{numeric_id:04d}-{slug}"
    except (ValueError, TypeError):
        return f"{frontend_id}-{slug}"


def save_problem_files(question: Dict[str, Any], artifacts: SolutionOutput) -> Path:
    """
    Save solution.cpp and README.md into the problem folder.
    """
    frontend_id = question.get("questionFrontendId", "0")
    slug = question.get("titleSlug", "unknown")
    folder_name = get_problem_folder_name(frontend_id, slug)

    prob_dir = REPO_PATH / folder_name
    prob_dir.mkdir(parents=True, exist_ok=True)

    cpp_path = prob_dir / "solution.cpp"
    readme_path = prob_dir / "README.md"

    cpp_path.write_text(artifacts.github_cpp_file, encoding="utf-8")
    readme_path.write_text(artifacts.github_readme_markdown, encoding="utf-8")

    return prob_dir


def commit_problem_files(
    folder_name: str,
    frontend_id: Any,
    title: str,
    difficulty: str,
    auto_push: bool = False,
) -> bool:
    """
    Stage and commit the problem folder to local Git.
    """
    try:
        ensure_git_repo()
        subprocess.run(
            ["git", "-C", str(REPO_PATH), "add", folder_name],
            check=True,
            capture_output=True,
            text=True,
        )

        commit_msg = f"feat({frontend_id}): add {title} ({difficulty})"
        result = subprocess.run(
            ["git", "-C", str(REPO_PATH), "commit", "-m", commit_msg],
            capture_output=True,
            text=True,
        )

        if auto_push and result.returncode == 0:
            subprocess.run(["git", "-C", str(REPO_PATH), "push", "origin", "main"], check=False)

        return result.returncode == 0
    except subprocess.CalledProcessError as e:
        print(f"[!] Git commit error: {e}")
        return False


def build_difficulty_badge(difficulty: str) -> str:
    d = difficulty.capitalize()
    if d == "Easy":
        return "`🟢 Easy`"
    elif d == "Medium":
        return "`🟡 Medium`"
    elif d == "Hard":
        return "`🔴 Hard`"
    return f"`{difficulty}`"


def generate_root_readme(
    problems: List[Dict[str, Any]],
    auto_commit: bool = True,
) -> Path:
    """
    Generates a clean, recruiter-friendly root README.md with problem metrics and master index table.
    """
    total = len(problems)
    easy = sum(1 for p in problems if p.get("difficulty") == "Easy")
    medium = sum(1 for p in problems if p.get("difficulty") == "Medium")
    hard = sum(1 for p in problems if p.get("difficulty") == "Hard")

    readme_content = f"""# 🚀 LeetCode Solutions & Community Editorials

An automated, recruiter-friendly repository of accepted LeetCode solutions in C++20 with in-depth algorithmic breakdowns, step-by-step intuition, complexity proofs, and synchronized LeetCode Community publications.

---

### 📊 Repository Statistics

| Total Solved | 🟢 Easy | 🟡 Medium | 🔴 Hard | Automation Engine |
| :---: | :---: | :---: | :---: | :---: |
| **{total}** | **{easy}** | **{medium}** | **{hard}** | **Gemini 2.5 Flash + LeetCode UGC** |

---

### 📚 Problem Index

| # | Title | Solution | Difficulty | Topics | LeetCode Post |
| :-: | :-- | :-: | :-: | :-- | :-: |
"""

    if not problems:
        readme_content += "| — | *No problems synchronized yet. Run `python main.py sync-recent` to start.* | — | — | — | — |\n"
    else:
        for p in problems:
            fid = p.get("frontend_id", "0")
            try:
                fid_int = int(fid)
                padded_id = f"{fid_int:04d}"
            except ValueError:
                padded_id = str(fid)

            slug = p.get("slug", "")
            title = p.get("title", slug.replace("-", " ").title())
            difficulty = p.get("difficulty", "Unknown")
            folder = p.get("folder_path") or get_problem_folder_name(fid, slug)
            tags = p.get("tags", [])
            tag_str = ", ".join(f"`{t}`" for t in tags[:3]) if tags else "—"

            prob_link = f"[{title}](https://leetcode.com/problems/{slug}/)"
            code_link = f"[C++](./{folder}/solution.cpp)"
            diff_badge = build_difficulty_badge(difficulty)

            lc_pub = p.get("lc_published")
            lc_slug = p.get("lc_post_slug")
            if lc_pub:
                if lc_slug:
                    post_link = f"[Editorial](https://leetcode.com/problems/{slug}/solutions/{lc_slug}/)"
                else:
                    post_link = f"[Community Post](https://leetcode.com/problems/{slug}/solutions/)"
            else:
                post_link = "—"

            readme_content += f"| {padded_id} | {prob_link} | {code_link} | {diff_badge} | {tag_str} | {post_link} |\n"

    readme_content += """
---

## 🛠️ Pipeline Architecture & How It Works

This repository is kept in sync using a zero-drift, single-shot pipeline:
1. **LeetCode GraphQL Fetcher:** Emulates Chrome TLS fingerprint (`curl_cffi` / JA3) to query accepted C++ submissions and problem metadata.
2. **Single-Shot Editorial Engine:** Grounded Gemini 2.5 Flash model produces canonical LeetCode UGC markdown, commented C++ code, and GitHub documentation in a single structured JSON response.
3. **UGC Publisher:** Automatically posts verified community solutions with strict anti-ban jitter cooldowns (`75s - 120s`).
4. **Local Git Sync:** Stages atomic commits directly without hitting GitHub Contents API secondary abuse limits.

*Automated with precision.*
"""

    root_readme_path = REPO_PATH / "README.md"
    root_readme_path.write_text(readme_content, encoding="utf-8")

    if auto_commit:
        try:
            ensure_git_repo()
            subprocess.run(
                ["git", "-C", str(REPO_PATH), "add", "README.md"],
                check=True,
                capture_output=True,
            )
            # Check if there are changes to commit
            status = subprocess.run(
                ["git", "-C", str(REPO_PATH), "status", "--porcelain", "README.md"],
                capture_output=True,
                text=True,
            )
            if status.stdout.strip():
                subprocess.run(
                    ["git", "-C", str(REPO_PATH), "commit", "-m", "docs: update root README index table"],
                    capture_output=True,
                )
        except Exception as e:
            print(f"[!] Warning updating git with root README: {e}")

    return root_readme_path
