import argparse
import random
import sys
import time
from datetime import datetime
from typing import Optional

from config import (
    LEETCODE_SESSION,
    LEETCODE_CSRF_TOKEN,
    LEETCODE_USERNAME,
    LC_PUBLISH_DELAY_MIN,
    LC_PUBLISH_DELAY_MAX,
    validate_config,
)
from state_manager import StateManager
from leetcode_client import LeetCodeClient
from editorial_generator import generate_artifacts
from git_sync import (
    save_problem_files,
    commit_problem_files,
    get_problem_folder_name,
    generate_root_readme,
    ensure_git_repo,
)


def process_submission(
    lc_client: LeetCodeClient,
    state_mgr: StateManager,
    submission_id: int,
    question_slug: str,
    dry_run: bool = False,
    skip_lc_publish: bool = False,
    enforce_cooldown: bool = True,
) -> bool:
    """
    Core pipeline unit:
    1. Fetch submission code, telemetry & question HTML from LeetCode
    2. Check if user already posted solution on LeetCode
    3. Generate structured editorial via Gemini 2.5 Flash
    4. Publish to LeetCode (if not published & not dry-run) with anti-ban jitter
    5. Save solution.cpp and README.md into local Git repository
    6. Commit locally and update state.json
    """
    print(f"\n{'='*65}")
    print(f"[*] Processing Question: {question_slug} (Submission #{submission_id})")
    print(f"{'='*65}")

    # 1. Fetch submission details
    try:
        details = lc_client.get_submission_details(submission_id)
    except Exception as e:
        print(f"[!] Failed to fetch submission details for #{submission_id}: {e}")
        return False

    q = details.get("question", {})
    frontend_id = q.get("questionFrontendId", "0")
    title = q.get("title", question_slug)
    difficulty = q.get("difficulty", "Unknown")
    folder_name = get_problem_folder_name(frontend_id, question_slug)

    print(f"[i] Title: #{frontend_id}. {title} [{difficulty}]")
    print(f"[i] Runtime: {details.get('runtime')} ms | Memory: {details.get('memory')} MB")

    # 2. Check if already posted on LeetCode Community
    already_posted_on_lc = False
    try:
        already_posted_on_lc = lc_client.has_user_posted_solution(question_slug)
        if already_posted_on_lc:
            print("[i] User has ALREADY published a solution article on LeetCode for this problem.")
    except Exception as e:
        print(f"[!] Warning checking LeetCode user solution: {e}")

    # 3. Generate structured artifacts via LLM
    print("[*] Prompting Gemini 2.5 Flash for high-signal C++ editorial & code...")
    try:
        artifacts = generate_artifacts(details)
    except Exception as e:
        print(f"[!] LLM Generation failed: {e}")
        return False

    print(f"[+] Editorial generated successfully: '{artifacts.lc_post_title}'")
    print(f"[+] Selected tag slugs: {artifacts.selected_tag_slugs}")

    # 4. Publish to LeetCode Community
    lc_published = False
    lc_article_uuid = None
    lc_post_slug = None

    if dry_run:
        print("[DRY-RUN] Skipping publication to LeetCode Community.")
    elif skip_lc_publish or already_posted_on_lc:
        print("[i] Skipping LeetCode article publication (already exists or disabled).")
        lc_published = already_posted_on_lc
    else:
        print("[*] Publishing solution to LeetCode Community UGC...")
        try:
            article = lc_client.publish_solution(
                question_slug=question_slug,
                title=artifacts.lc_post_title,
                content=artifacts.lc_post_markdown,
                tags=artifacts.selected_tag_slugs,
            )
            lc_published = True
            lc_article_uuid = article.get("uuid")
            lc_post_slug = article.get("slug")
            print(f"[✓] Published to LeetCode! Article UUID: {lc_article_uuid} | Slug: {lc_post_slug}")

            # Enforce anti-ban cooldown jitter if more tasks might follow
            if enforce_cooldown:
                cooldown = random.uniform(LC_PUBLISH_DELAY_MIN, LC_PUBLISH_DELAY_MAX)
                print(f"[⏱] Applying anti-ban cooldown: sleeping for {cooldown:.1f}s...")
                time.sleep(cooldown)

        except Exception as e:
            print(f"[!] LeetCode publication failed: {e}")

    # 5. Save local files in repository
    prob_dir, rel_folder_path = save_problem_files(q, artifacts)
    print(f"[*] Wrote solution.cpp and README.md into '{rel_folder_path}'")

    # 6. Git commit and PR creation
    commit_problem_files(
        rel_folder_path=rel_folder_path,
        frontend_id=frontend_id,
        title=title,
        difficulty=difficulty,
        slug=question_slug,
    )

    # 7. Record in state
    state_mgr.record_synced(
        slug=question_slug,
        frontend_id=frontend_id,
        title=title,
        difficulty=difficulty,
        submission_id=submission_id,
        folder_path=rel_folder_path,
        lc_published=lc_published,
        lc_article_uuid=lc_article_uuid,
        lc_post_slug=lc_post_slug,
        tags=artifacts.selected_tag_slugs,
    )
    print(f"[✓] Successfully recorded '{question_slug}' in local state!")
    return True


def cmd_sync_recent(args):
    validate_config()
    ensure_git_repo()
    state_mgr = StateManager()
    lc_client = LeetCodeClient(LEETCODE_SESSION, LEETCODE_CSRF_TOKEN, LEETCODE_USERNAME)

    print(f"[*] Fetching up to {args.limit} recent accepted submissions for '{LEETCODE_USERNAME}'...")
    recent_subs = lc_client.get_recent_ac_submissions(limit=args.limit)
    print(f"[+] Found {len(recent_subs)} recent accepted submissions.")

    # Deduplicate by slug (latest submission wins)
    unique_recent = {}
    for sub in recent_subs:
        slug = sub.get("titleSlug")
        if slug and slug not in unique_recent:
            unique_recent[slug] = sub

    processed_count = 0
    for slug, sub in unique_recent.items():
        if not args.force and state_mgr.is_processed(slug):
            print(f"[i] Skipping '{slug}': already indexed in state.json.")
            continue

        sub_id = int(sub["id"])
        # Fetch latest C++ submission ID for this slug
        c_sub = lc_client.get_latest_ac_submission_for_question(slug, preferred_lang="cpp")
        if c_sub:
            sub_id = int(c_sub["id"])

        success = process_submission(
            lc_client=lc_client,
            state_mgr=state_mgr,
            submission_id=sub_id,
            question_slug=slug,
            dry_run=args.dry_run,
            skip_lc_publish=args.no_lc_publish,
            enforce_cooldown=not args.dry_run and not args.no_lc_publish,
        )
        if success:
            processed_count += 1

    # Update root README index table
    generate_root_readme(state_mgr.get_all_synced_problems(), auto_commit=True)
    print(f"\n[✓] Done! Synced {processed_count} new problem(s). Root README index updated.")


def cmd_backfill(args):
    validate_config()
    ensure_git_repo()
    state_mgr = StateManager()
    lc_client = LeetCodeClient(LEETCODE_SESSION, LEETCODE_CSRF_TOKEN, LEETCODE_USERNAME)

    print(f"[*] Querying all historically solved problems for '{LEETCODE_USERNAME}' via problemsetQuestionList...")
    all_solved = lc_client.get_all_solved_questions()
    print(f"[+] Total solved questions found on LeetCode: {len(all_solved)}")

    # Filter unindexed problems
    to_process = []
    for q in all_solved:
        slug = q.get("titleSlug")
        fid = q.get("questionFrontendId")
        if not args.force and (state_mgr.is_processed(slug) or state_mgr.is_processed(fid)):
            continue
        to_process.append(q)

    print(f"[+] Found {len(to_process)} unindexed problems ready for backfill.")

    if args.limit and args.limit > 0:
        to_process = to_process[: args.limit]
        print(f"[i] Limiting backfill batch to {len(to_process)} problem(s).")

    processed_count = 0
    for idx, q in enumerate(to_process, 1):
        slug = q.get("titleSlug")
        fid = q.get("questionFrontendId")
        print(f"\n--> Backfill Progress [{idx}/{len(to_process)}]: #{fid} {slug}")

        # Fetch latest accepted C++ submission
        sub = lc_client.get_latest_ac_submission_for_question(slug, preferred_lang="cpp")
        if not sub:
            print(f"[!] Warning: No accepted C++ submission found for '{slug}'. Skipping.")
            continue

        sub_id = int(sub["id"])
        success = process_submission(
            lc_client=lc_client,
            state_mgr=state_mgr,
            submission_id=sub_id,
            question_slug=slug,
            dry_run=args.dry_run,
            skip_lc_publish=args.no_lc_publish,
            enforce_cooldown=not args.dry_run and not args.no_lc_publish,
        )
        if success:
            processed_count += 1

        # Intermediate root README update every 5 problems
        if processed_count % 5 == 0:
            generate_root_readme(state_mgr.get_all_synced_problems(), auto_commit=True)

    # Final root README update
    generate_root_readme(state_mgr.get_all_synced_problems(), auto_commit=True)
    print(f"\n[✓] Backfill complete! Processed {processed_count} problem(s).")


def cmd_sync_one(args):
    validate_config()
    ensure_git_repo()
    state_mgr = StateManager()
    lc_client = LeetCodeClient(LEETCODE_SESSION, LEETCODE_CSRF_TOKEN, LEETCODE_USERNAME)

    slug = args.slug.strip().lower()
    submission_id = args.submission_id

    if not submission_id:
        print(f"[*] Searching latest C++ accepted submission for '{slug}'...")
        sub = lc_client.get_latest_ac_submission_for_question(slug, preferred_lang="cpp")
        if not sub:
            print(f"[!] Could not find any accepted submission for '{slug}'.")
            return
        submission_id = int(sub["id"])

    process_submission(
        lc_client=lc_client,
        state_mgr=state_mgr,
        submission_id=submission_id,
        question_slug=slug,
        dry_run=args.dry_run,
        skip_lc_publish=args.no_lc_publish,
        enforce_cooldown=False,
    )
    generate_root_readme(state_mgr.get_all_synced_problems(), auto_commit=True)


def cmd_update_readme(args):
    state_mgr = StateManager()
    problems = state_mgr.get_all_synced_problems()
    readme_path = generate_root_readme(problems, auto_commit=not args.no_commit)
    print(f"[✓] Root README regenerated at '{readme_path}' with {len(problems)} problem entries.")


def cmd_status(args):
    state_mgr = StateManager()
    summary = state_mgr.get_summary()
    print("\n" + "=" * 50)
    print(" 📊 LeetCode Pipeline Synchronization Status")
    print("=" * 50)
    print(f" Total Problems Synced: {summary['total_synced']}")
    print(f" LeetCode UGC Articles: {summary['lc_published']}")
    print(f" Breakdown by Difficulty:")
    for diff, count in summary["difficulties"].items():
        print(f"   - {diff:8s}: {count}")
    print(f" Last Sync Timestamp:  {summary['last_synced_at'] or 'Never'}")
    print("=" * 50 + "\n")


def cmd_serve_webhook(args):
    from webhook_server import run_server
    run_server(host=args.host, port=args.port)


def main():
    parser = argparse.ArgumentParser(
        description="End-to-end LeetCode-to-Community-and-GitHub Pipeline"
    )
    subparsers = parser.add_subparsers(dest="command", required=True)

    # Subcommand: sync-recent
    p_recent = subparsers.add_parser("sync-recent", help="Sync recent accepted submissions")
    p_recent.add_argument("--limit", type=int, default=20, help="Number of recent submissions to check (default: 20)")
    p_recent.add_argument("--dry-run", action="store_true", help="Generate code & markdown locally without publishing to LeetCode")
    p_recent.add_argument("--no-lc-publish", action="store_true", help="Commit to GitHub only without publishing to LeetCode UGC")
    p_recent.add_argument("--force", action="store_true", help="Re-process problems even if already present in state.json")
    p_recent.set_defaults(func=cmd_sync_recent)

    # Subcommand: backfill
    p_backfill = subparsers.add_parser("backfill", help="Backfill all historically solved LeetCode problems")
    p_backfill.add_argument("--limit", type=int, default=0, help="Limit number of problems to backfill (0 = all)")
    p_backfill.add_argument("--dry-run", action="store_true", help="Generate code & markdown locally without publishing to LeetCode")
    p_backfill.add_argument("--no-lc-publish", action="store_true", help="Commit to GitHub only without publishing to LeetCode UGC")
    p_backfill.add_argument("--force", action="store_true", help="Force re-processing of already synced problems")
    p_backfill.set_defaults(func=cmd_backfill)

    # Subcommand: sync-one
    p_one = subparsers.add_parser("sync-one", help="Sync a specific problem by its slug or frontend ID")
    p_one.add_argument("slug", help="LeetCode question slug (e.g., two-sum, lru-cache)")
    p_one.add_argument("--submission-id", type=int, default=None, help="Explicit submission ID (optional)")
    p_one.add_argument("--dry-run", action="store_true", help="Generate code & markdown locally without publishing to LeetCode")
    p_one.add_argument("--no-lc-publish", action="store_true", help="Commit to GitHub only without publishing to LeetCode UGC")
    p_one.set_defaults(func=cmd_sync_one)

    # Subcommand: update-readme
    p_readme = subparsers.add_parser("update-readme", help="Regenerate the root README.md table of contents")
    p_readme.add_argument("--no-commit", action="store_true", help="Do not commit the updated README.md to Git")
    p_readme.set_defaults(func=cmd_update_readme)

    # Subcommand: status
    p_status = subparsers.add_parser("status", help="Show pipeline statistics and sync status")
    p_status.set_defaults(func=cmd_status)

    # Subcommand: serve-webhook
    p_webhook = subparsers.add_parser("serve-webhook", help="Start local webhook daemon for Chrome Extension triggers")
    p_webhook.add_argument("--host", default="127.0.0.1", help="Host address (default: 127.0.0.1)")
    p_webhook.add_argument("--port", type=int, default=8765, help="Port (default: 8765)")
    p_webhook.set_defaults(func=cmd_serve_webhook)

    args = parser.parse_args()
    args.func(args)


if __name__ == "__main__":
    main()
