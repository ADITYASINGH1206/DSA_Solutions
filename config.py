import os
from pathlib import Path
from dotenv import load_dotenv

# Base directory for the repository (current folder)
BASE_DIR = Path(__file__).resolve().parent

# Load .env file
load_dotenv(BASE_DIR / ".env")

# LeetCode Credentials
LEETCODE_SESSION = os.getenv("LEETCODE_SESSION", "").strip()
LEETCODE_CSRF_TOKEN = os.getenv("LEETCODE_CSRF_TOKEN", "").strip()
LEETCODE_USERNAME = os.getenv("LEETCODE_USERNAME", "").strip()

# Gemini API Credentials
GEMINI_API_KEY = os.getenv("GEMINI_API_KEY", "").strip()
GEMINI_MODEL = os.getenv("GEMINI_MODEL", "gemini-2.5-flash").strip()

# Anti-ban Jitter Delays (seconds)
LC_PUBLISH_DELAY_MIN = int(os.getenv("LC_PUBLISH_DELAY_MIN", "75"))
LC_PUBLISH_DELAY_MAX = int(os.getenv("LC_PUBLISH_DELAY_MAX", "120"))

# File Paths
REPO_PATH = BASE_DIR
SOLUTIONS_SUBDIR = os.getenv("GITHUB_REPO_DIR", "Solutions").strip()
SOLUTIONS_DIR = (BASE_DIR / SOLUTIONS_SUBDIR).resolve() if SOLUTIONS_SUBDIR and SOLUTIONS_SUBDIR != "." else BASE_DIR
STATE_FILE = Path(os.getenv("STATE_FILE", str(BASE_DIR / "state.json"))).resolve()

# Webhook Server
WEBHOOK_HOST = os.getenv("WEBHOOK_HOST", "127.0.0.1")
WEBHOOK_PORT = int(os.getenv("WEBHOOK_PORT", "8765"))

# Git Remote Sync Settings
GITHUB_AUTO_PUSH = os.getenv("GITHUB_AUTO_PUSH", "false").lower() in ("true", "1", "yes")
GITHUB_REMOTE_URL = os.getenv("GITHUB_REMOTE_URL", "").strip()
GITHUB_CREATE_PR = os.getenv("GITHUB_CREATE_PR", "true").lower() in ("true", "1", "yes")
PR_BATCH_SIZE = int(os.getenv("PR_BATCH_SIZE", "10"))


def validate_config(require_session: bool = True, require_gemini: bool = True):
    """
    Validate that required environment variables are set.
    Prints informative troubleshooting instructions if anything is missing.
    """
    missing = []
    if require_session:
        if not LEETCODE_SESSION:
            missing.append("LEETCODE_SESSION")
        if not LEETCODE_CSRF_TOKEN:
            missing.append("LEETCODE_CSRF_TOKEN")
        if not LEETCODE_USERNAME:
            missing.append("LEETCODE_USERNAME")

    if require_gemini:
        if not GEMINI_API_KEY:
            missing.append("GEMINI_API_KEY")

    if missing:
        error_msg = (
            f"\n[!] Missing required configuration in .env:\n"
            + "\n".join(f"    - {var}" for var in missing)
            + "\n\nPlease copy .env.example to .env and provide your credentials:"
            + "\n    cp .env.example .env\n"
        )
        raise ValueError(error_msg)
