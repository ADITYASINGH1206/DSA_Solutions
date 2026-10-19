import json
import queue
import threading
from http.server import HTTPServer, BaseHTTPRequestHandler
from typing import Optional

from config import (
    WEBHOOK_HOST,
    WEBHOOK_PORT,
    LEETCODE_SESSION,
    LEETCODE_CSRF_TOKEN,
    LEETCODE_USERNAME,
)
from state_manager import StateManager
from leetcode_client import LeetCodeClient
from git_sync import generate_root_readme, ensure_git_repo

# Task queue for processing submissions sequentially
task_queue: "queue.Queue[dict]" = queue.Queue()


def worker_loop():
    """
    Background worker that executes incoming synchronization jobs sequentially
    to respect LeetCode rate limits and avoid Git merge conflicts.
    """
    from main import process_submission

    while True:
        task = task_queue.get()
        if task is None:
            break

        submission_id = task.get("submissionId")
        question_slug = task.get("questionSlug")

        print(f"\n[Webhook Worker] Picked up task: {question_slug} (#{submission_id})")
        try:
            ensure_git_repo()
            state_mgr = StateManager()
            lc_client = LeetCodeClient(LEETCODE_SESSION, LEETCODE_CSRF_TOKEN, LEETCODE_USERNAME)

            # If submission_id wasn't provided, fetch the latest C++ accepted submission
            if not submission_id and question_slug:
                sub = lc_client.get_latest_ac_submission_for_question(question_slug, preferred_lang="cpp")
                if sub:
                    submission_id = int(sub["id"])

            if submission_id and question_slug:
                process_submission(
                    lc_client=lc_client,
                    state_mgr=state_mgr,
                    submission_id=submission_id,
                    question_slug=question_slug,
                    dry_run=False,
                    skip_lc_publish=False,
                    enforce_cooldown=True,
                )
                generate_root_readme(state_mgr.get_all_synced_problems(), auto_commit=True)
            else:
                print(f"[Webhook Worker] Missing submissionId or questionSlug in task: {task}")
        except Exception as e:
            print(f"[Webhook Worker] Error processing submission: {e}")
        finally:
            task_queue.task_done()


class WebhookHandler(BaseHTTPRequestHandler):
    """
    HTTP handler with CORS support to receive live submissions from Chrome Extension.
    """

    def _set_cors_headers(self):
        self.send_header("Access-Control-Allow-Origin", "*")
        self.send_header("Access-Control-Allow-Methods", "POST, GET, OPTIONS")
        self.send_header("Access-Control-Allow-Headers", "Content-Type, Authorization")

    def do_OPTIONS(self):
        self.send_response(204)
        self._set_cors_headers()
        self.end_headers()

    def do_GET(self):
        if self.path == "/health":
            self.send_response(200)
            self._set_cors_headers()
            self.send_header("Content-Type", "application/json")
            self.end_headers()
            response = {"status": "ok", "queued_tasks": task_queue.qsize()}
            self.wfile.write(json.dumps(response).encode("utf-8"))
        else:
            self.send_response(404)
            self.end_headers()

    def do_POST(self):
        if self.path == "/api/sync-submission":
            content_length = int(self.headers.get("Content-Length", 0))
            body = self.rfile.read(content_length).decode("utf-8")

            try:
                data = json.loads(body) if body else {}
                question_slug = data.get("questionSlug")
                submission_id = data.get("submissionId")

                if not question_slug and not submission_id:
                    self.send_response(400)
                    self._set_cors_headers()
                    self.send_header("Content-Type", "application/json")
                    self.end_headers()
                    self.wfile.write(json.dumps({"error": "Missing questionSlug or submissionId"}).encode("utf-8"))
                    return

                # Enqueue the job for sequential processing
                task_queue.put({
                    "submissionId": int(submission_id) if submission_id else None,
                    "questionSlug": question_slug,
                })

                self.send_response(200)
                self._set_cors_headers()
                self.send_header("Content-Type", "application/json")
                self.end_headers()
                resp = {
                    "status": "enqueued",
                    "message": f"Queued processing for {question_slug}",
                    "queue_length": task_queue.qsize(),
                }
                self.wfile.write(json.dumps(resp).encode("utf-8"))

            except Exception as e:
                self.send_response(500)
                self._set_cors_headers()
                self.send_header("Content-Type", "application/json")
                self.end_headers()
                self.wfile.write(json.dumps({"error": str(e)}).encode("utf-8"))
        else:
            self.send_response(404)
            self.end_headers()

    def log_message(self, format, *args):
        # Clean terminal logging
        print(f"[Webhook Server] {args[0]} - {args[1]} {args[2]}")


def run_server(host: str = WEBHOOK_HOST, port: int = WEBHOOK_PORT):
    # Start background worker thread
    worker_thread = threading.Thread(target=worker_loop, daemon=True)
    worker_thread.start()

    server = HTTPServer((host, port), WebhookHandler)
    print(f"\n[🚀] Local LeetCode Sync Webhook daemon running at http://{host}:{port}")
    print(f"[i] Ready to receive live submission triggers from Chrome Extension.")
    print(f"[i] Press Ctrl+C to stop.\n")
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print("\nShutting down webhook server...")
        server.server_close()
