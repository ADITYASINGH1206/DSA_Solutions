import os
import subprocess
from datetime import datetime
from pathlib import Path
from typing import List, Dict, Any, Optional, Tuple

from config import (
    REPO_PATH,
    SOLUTIONS_DIR,
    GITHUB_AUTO_PUSH,
    GITHUB_REMOTE_URL,
    GITHUB_CREATE_PR,
    PR_BATCH_SIZE,
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

    try:
        rel_path = str(prob_dir.relative_to(REPO_PATH))
    except ValueError:
        rel_path = folder_name

    return prob_dir, rel_path


def start_batch_branch(batch_index: Optional[int] = None) -> str:
    """
    Prepare a fresh Git feature branch for a batch of solutions.
    """
    ensure_git_repo()
    timestamp = datetime.now().strftime("%Y%m%d-%H%M%S")
    idx_str = f"batch-{batch_index}-" if batch_index else "batch-"
    branch_name = f"solutions/{idx_str}{timestamp}"

    # Return to main and pull latest remote changes if available
    subprocess.run(["git", "-C", str(REPO_PATH), "checkout", "main"], capture_output=True)
    subprocess.run(["git", "-C", str(REPO_PATH), "pull", "origin", "main", "--rebase"], capture_output=True)

    # Create and checkout feature branch
    subprocess.run(["git", "-C", str(REPO_PATH), "checkout", "-B", branch_name], check=True, capture_output=True)
    print(f"[GIT] Checked out batch branch: '{branch_name}'")
    return branch_name


def commit_problem_to_branch(
    rel_folder_path: str,
    frontend_id: Any,
    title: str,
    difficulty: str,
) -> bool:
    """
    Stage and commit a single problem solution to the currently checked out branch.
    """
    try:
        subprocess.run(
            ["git", "-C", str(REPO_PATH), "add", rel_folder_path],
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
        return result.returncode == 0
    except subprocess.CalledProcessError as e:
        print(f"[GIT] Commit error for problem {frontend_id}: {e}")
        return False


def push_batch_and_create_pr(
    branch_name: str,
    batch_problems: List[Dict[str, Any]],
) -> Optional[str]:
    """
    Push the batch branch to origin and open a single Pull Request containing all batched solutions.
    """
    if not batch_problems:
        return None

    try:
        print(f"[GIT] Pushing branch '{branch_name}' to remote origin...")
        push_res = subprocess.run(
            ["git", "-C", str(REPO_PATH), "push", "-u", "origin", branch_name, "--force"],
            capture_output=True,
            text=True,
        )
        if push_res.returncode != 0:
            print(f"[GIT] Warning pushing branch: {push_res.stderr.strip()}")

        count = len(batch_problems)
        if count == 1:
            p = batch_problems[0]
            pr_title = f"feat({p['frontend_id']}): add {p['title']} ({p['difficulty']})"
        else:
            first_id = batch_problems[0]["frontend_id"]
            last_id = batch_problems[-1]["frontend_id"]
            pr_title = f"feat(solutions): add batch of {count} solutions (#{first_id} - #{last_id})"

        table_rows = []
        for p in batch_problems:
            fid = p.get("frontend_id", "0")
            title = p.get("title", "")
            diff = p.get("difficulty", "")
            slug = p.get("slug", "")
            path = p.get("folder_path", "")
            table_rows.append(f"| {fid} | [{title}](https://leetcode.com/problems/{slug}/) | {diff} | C++20 | `{path}` |")

        table_body = "\n".join(table_rows)

        pr_body = f"""## LeetCode Solutions Batch ({count} problems)

### Synchronized Solutions
| # | Title | Difficulty | Language | Location |
| :-: | :-- | :-: | :-: | :-- |
{table_body}

### Summary
Each problem contains:
- `solution.cpp`: Standalone C++20 implementation with STL optimizations.
- `README.md`: Problem statement, intuition, approach breakdown, and complexity analysis.

Generated by LeetCode-to-GitHub Pipeline.
"""

        print(f"[PR] Opening GitHub Pull Request for batch of {count} solutions...")
        pr_res = subprocess.run(
            [
                "gh", "pr", "create",
                "--base", "main",
                "--head", branch_name,
                "--title", pr_title,
                "--body", pr_body,
            ],
            cwd=str(REPO_PATH),
            capture_output=True,
            text=True,
        )

        pr_url = None
        if pr_res.returncode == 0:
            pr_url = pr_res.stdout.strip()
            print(f"[PR] Pull Request successfully created: {pr_url}")
        else:
            err = pr_res.stderr.strip()
            if "already exists" in err.lower():
                print(f"[PR] Pull Request already exists for branch '{branch_name}'.")
            else:
                print(f"[PR] Notice from 'gh pr create': {err}")

        # Return to main branch
        subprocess.run(["git", "-C", str(REPO_PATH), "checkout", "main"], capture_output=True)
        return pr_url

    except Exception as e:
        print(f"[GIT] Failed during batch PR push: {e}")
        subprocess.run(["git", "-C", str(REPO_PATH), "checkout", "main"], capture_output=True)
        return None


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
    Standard single-solution commit function (used for single runs).
    """
    if auto_push is None:
        auto_push = GITHUB_AUTO_PUSH
    if create_pr is None:
        create_pr = GITHUB_CREATE_PR

    single_item = [{
        "frontend_id": frontend_id,
        "title": title,
        "difficulty": difficulty,
        "slug": slug,
        "folder_path": rel_folder_path,
    }]

    if create_pr:
        branch_name = f"solution/{frontend_id}-{slug or title.lower().replace(' ', '-')}"
        start_batch_branch()
        subprocess.run(["git", "-C", str(REPO_PATH), "checkout", "-B", branch_name], check=True, capture_output=True)
        commit_problem_to_branch(rel_folder_path, frontend_id, title, difficulty)
        push_batch_and_create_pr(branch_name, single_item)
        return True
    else:
        try:
            ensure_git_repo()
            subprocess.run(["git", "-C", str(REPO_PATH), "add", rel_folder_path], check=True, capture_output=True)
            commit_msg = f"feat({frontend_id}): add {title} ({difficulty})"
            res = subprocess.run(["git", "-C", str(REPO_PATH), "commit", "-m", commit_msg], capture_output=True, text=True)
            if auto_push and res.returncode == 0:
                subprocess.run(["git", "-C", str(REPO_PATH), "push", "origin", "main"], capture_output=True)
            return res.returncode == 0
        except Exception as e:
            print(f"[GIT] Commit error: {e}")
            return False


def build_difficulty_badge(difficulty: str) -> str:
    """
    Clean, emoji-free difficulty representation.
    """
    d = difficulty.capitalize()
    return f"`{d}`"


def generate_root_readme(
    problems: List[Dict[str, Any]],
    auto_commit: bool = True,
) -> Path:
    """
    Generates a clean root README.md with metrics and master index table without emojis.
    """
    total = len(problems)
    easy = sum(1 for p in problems if p.get("difficulty") == "Easy")
    medium = sum(1 for p in problems if p.get("difficulty") == "Medium")
    hard = sum(1 for p in problems if p.get("difficulty") == "Hard")

    readme_content = f"""# LeetCode Solutions & Community Editorials

An automated repository of accepted LeetCode solutions in modern C++20 with algorithmic breakdowns, step-by-step intuition, complexity proofs, and synchronized LeetCode Community publications.

---

### Repository Statistics

| Total Solved | Easy | Medium | Hard | Automation Engine |
| :---: | :---: | :---: | :---: | :---: |
| **{total}** | **{easy}** | **{medium}** | **{hard}** | **Gemini 2.5 Flash + LeetCode UGC** |

---

### Problem Index

| # | Title | Solution | Difficulty | Topics | LeetCode Post |
| :-: | :-- | :-: | :-: | :-- | :-: |
"""

    if not problems:
        readme_content += "| — | *No problems synchronized yet. Run `python3 main.py sync-recent` to start.* | — | — | — | — |\n"
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

## Pipeline Architecture & How It Works

This repository is kept in sync using a zero-drift, single-shot pipeline:
1. **LeetCode GraphQL Fetcher:** Emulates Chrome TLS fingerprint (`curl_cffi` / JA3) to query accepted C++ submissions and problem metadata.
2. **Single-Shot Editorial Engine:** Grounded Gemini 2.5 Flash model produces canonical LeetCode UGC markdown, commented C++ code, and GitHub documentation in a single structured JSON response.
3. **UGC Publisher:** Automatically posts verified community solutions with strict anti-ban jitter cooldowns (75s - 120s).
4. **Pull Request Workflow:** Solutions are grouped into batches of 10 per Pull Request, creating isolated Git branches and opening PRs automatically via the GitHub CLI.
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
            print(f"[GIT] Warning updating git with root README: {e}")

    return root_readme_path
