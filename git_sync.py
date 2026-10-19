import os
import subprocess
from pathlib import Path
from typing import List, Dict, Any, Optional, Tuple

from config import (
    REPO_PATH,
    SOLUTIONS_DIR,
    GITHUB_AUTO_PUSH,
    GITHUB_REMOTE_URL,
    GITHUB_CREATE_PR,
)
from editorial_generator import SolutionOutput


def ensure_git_repo():
    """
    Ensure the REPO_PATH is initialized as a git repository and configure remote if provided.
    """
    git_dir = REPO_PATH / ".git"
    if not git_dir.exists():
        subprocess.run(["git", "-C", str(REPO_PATH), "init", "-b", "main"], check=True)

    if GITHUB_REMOTE_URL:
        remotes = subprocess.run(
            ["git", "-C", str(REPO_PATH), "remote"],
            capture_output=True,
            text=True,
        ).stdout.split()
        if "origin" not in remotes:
            subprocess.run(["git", "-C", str(REPO_PATH), "remote", "add", "origin", GITHUB_REMOTE_URL], check=False)
        else:
            subprocess.run(["git", "-C", str(REPO_PATH), "remote", "set-url", "origin", GITHUB_REMOTE_URL], check=False)


def get_problem_folder_name(frontend_id: Any, slug: str) -> str:
    """
    Format folder as 0001-two-sum (zero-padded 4-digit ID).
    """
    try:
        numeric_id = int(frontend_id)
        return f"{numeric_id:04d}-{slug}"
    except (ValueError, TypeError):
        return f"{frontend_id}-{slug}"


def save_problem_files(question: Dict[str, Any], artifacts: SolutionOutput) -> Tuple[Path, str]:
    """
    Save solution.cpp and README.md into the configured solutions directory (e.g., Solutions/2089-find-target-indices-after-sorting-array).
    Returns (absolute_path, relative_path_from_repo_root).
    """
    frontend_id = question.get("questionFrontendId", "0")
    slug = question.get("titleSlug", "unknown")
    folder_name = get_problem_folder_name(frontend_id, slug)

    prob_dir = SOLUTIONS_DIR / folder_name
    prob_dir.mkdir(parents=True, exist_ok=True)

    cpp_path = prob_dir / "solution.cpp"
    readme_path = prob_dir / "README.md"

    cpp_path.write_text(artifacts.github_cpp_file, encoding="utf-8")
    readme_path.write_text(artifacts.github_readme_markdown, encoding="utf-8")

    # Relative path from Git root for staging/linking (e.g. "Solutions/2089-find-target-indices-after-sorting-array")
    try:
        rel_path = str(prob_dir.relative_to(REPO_PATH))
    except ValueError:
        rel_path = folder_name

    return prob_dir, rel_path


def commit_problem_files(
    rel_folder_path: str,
    frontend_id: Any,
    title: str,
    difficulty: str,
    slug: str = "",
    auto_push: Optional[bool] = None,
    create_pr: Optional[bool] = None,
) -> bool:
    """
    Commit solution files. If create_pr is enabled, creates a dedicated branch,
    pushes it to origin, and opens a GitHub Pull Request via the GitHub CLI (gh).
    """
    if auto_push is None:
        auto_push = GITHUB_AUTO_PUSH
    if create_pr is None:
        create_pr = GITHUB_CREATE_PR

    try:
        ensure_git_repo()
        commit_msg = f"feat({frontend_id}): add {title} ({difficulty})"

        if create_pr:
            # Branch-per-solution PR workflow
            branch_name = f"solution/{frontend_id}-{slug or title.lower().replace(' ', '-')}"
            print(f"[*] Creating dedicated Git branch: '{branch_name}'")

            # Check out new branch
            subprocess.run(
                ["git", "-C", str(REPO_PATH), "checkout", "-B", branch_name],
                check=True,
                capture_output=True,
                text=True,
            )

            # Stage problem files
            subprocess.run(
                ["git", "-C", str(REPO_PATH), "add", rel_folder_path],
                check=True,
                capture_output=True,
                text=True,
            )

            # Commit
            subprocess.run(
                ["git", "-C", str(REPO_PATH), "commit", "-m", commit_msg],
                check=True,
                capture_output=True,
                text=True,
            )

            # Push branch to origin
            print(f"[*] Pushing branch '{branch_name}' to remote origin...")
            push_res = subprocess.run(
                ["git", "-C", str(REPO_PATH), "push", "-u", "origin", branch_name, "--force"],
                capture_output=True,
                text=True,
            )
            if push_res.returncode != 0:
                print(f"[!] Warning pushing branch: {push_res.stderr.strip()}")

            # Create Pull Request via gh
            pr_body = f"""## 🚀 Solution & Editorial for [{frontend_id}. {title}](https://leetcode.com/problems/{slug}/)

### 📊 Details
- **Problem ID:** #{frontend_id}
- **Difficulty:** {difficulty}
- **Language:** C++20
- **Location:** `{rel_folder_path}`

### 📝 Included Files
- `solution.cpp` (Commented C++20 implementation)
- `README.md` (Problem statement + comprehensive editorial breakdown)

*Automated by LeetCode Pipeline Engine.*
"""
            print(f"[*] Opening GitHub Pull Request for #{frontend_id}...")
            pr_res = subprocess.run(
                [
                    "gh", "pr", "create",
                    "--base", "main",
                    "--head", branch_name,
                    "--title", commit_msg,
                    "--body", pr_body,
                ],
                cwd=str(REPO_PATH),
                capture_output=True,
                text=True,
            )
            if pr_res.returncode == 0:
                pr_url = pr_res.stdout.strip()
                print(f"[✓] Pull Request successfully created: {pr_url}")
            else:
                err_text = pr_res.stderr.strip()
                if "already exists" in err_text.lower():
                    print(f"[i] Pull Request already exists for branch '{branch_name}'.")
                else:
                    print(f"[!] Notice: 'gh pr create' output: {err_text}")

            # Return to main branch
            subprocess.run(["git", "-C", str(REPO_PATH), "checkout", "main"], capture_output=True)

        else:
            # Direct commit on main
            subprocess.run(
                ["git", "-C", str(REPO_PATH), "add", rel_folder_path],
                check=True,
                capture_output=True,
                text=True,
            )
            result = subprocess.run(
                ["git", "-C", str(REPO_PATH), "commit", "-m", commit_msg],
                capture_output=True,
                text=True,
            )
            if auto_push and result.returncode == 0:
                push_res = subprocess.run(
                    ["git", "-C", str(REPO_PATH), "push", "origin", "main"],
                    capture_output=True,
                    text=True,
                )
                if push_res.returncode == 0:
                    print(f"[✓] Pushed changes to GitHub remote.")
                else:
                    print(f"[!] Warning: Git push failed: {push_res.stderr.strip()}")

        return True

    except Exception as e:
        print(f"[!] Git operation error: {e}")
        # Ensure we return to main on error
        subprocess.run(["git", "-C", str(REPO_PATH), "checkout", "main"], capture_output=True)
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
            folder = p.get("folder_path") or f"Solutions/{get_problem_folder_name(fid, slug)}"
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
4. **Pull Request Workflow:** Each problem creates an isolated Git branch, commits `solution.cpp` and `README.md`, pushes to origin, and opens a Pull Request on GitHub.

*Automated with precision.*
"""

    root_readme_path = REPO_PATH / "README.md"
    root_readme_path.write_text(readme_content, encoding="utf-8")

    if auto_commit:
        try:
            ensure_git_repo()
            subprocess.run(["git", "-C", str(REPO_PATH), "checkout", "main"], capture_output=True)
            subprocess.run(
                ["git", "-C", str(REPO_PATH), "add", "README.md"],
                check=True,
                capture_output=True,
            )
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
                if GITHUB_AUTO_PUSH:
                    subprocess.run(["git", "-C", str(REPO_PATH), "push", "origin", "main"], capture_output=True)
        except Exception as e:
            print(f"[!] Warning updating git with root README: {e}")

    return root_readme_path
