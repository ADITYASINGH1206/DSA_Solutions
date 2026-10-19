// Content script for LeetCode problem pages

(function () {
  console.log("[LC-Sync] Content script initialized on LeetCode");

  function getQuestionSlug() {
    const match = window.location.pathname.match(/\/problems\/([^/]+)/);
    return match ? match[1] : null;
  }

  function showToast(message, type = "info") {
    let container = document.getElementById("lc-sync-toast-container");
    if (!container) {
      container = document.createElement("div");
      container.id = "lc-sync-toast-container";
      document.body.appendChild(container);
    }

    const toast = document.createElement("div");
    toast.className = `lc-sync-toast lc-sync-toast-${type}`;
    toast.innerHTML = `
      <div class="lc-sync-toast-header">
        <strong>LeetCode Pipeline</strong>
      </div>
      <div class="lc-sync-toast-body">${message}</div>
    `;

    container.appendChild(toast);
    setTimeout(() => {
      toast.classList.add("lc-sync-toast-fade");
      setTimeout(() => toast.remove(), 400);
    }, 4500);
  }

  function sendSyncRequest(submissionId = null) {
    const slug = getQuestionSlug();
    if (!slug) {
      showToast("Could not determine current question slug.", "error");
      return;
    }

    showToast(`Sending <strong>${slug}</strong> to local pipeline daemon...`, "info");

    chrome.runtime.sendMessage(
      {
        type: "TRIGGER_SYNC",
        payload: {
          questionSlug: slug,
          submissionId: submissionId,
        },
      },
      (response) => {
        if (chrome.runtime.lastError) {
          showToast(`Extension error: ${chrome.runtime.lastError.message}`, "error");
          return;
        }

        if (response && response.success) {
          showToast(`✓ Enqueued! Pipeline is generating solution & syncing to GitHub.`, "success");
        } else {
          const err = response ? response.error : "Unknown error connecting to local daemon";
          showToast(`⚠️ ${err}`, "error");
        }
      }
    );
  }

  // Inject a sleek floating quick-action button
  function injectActionButton() {
    if (document.getElementById("lc-sync-trigger-btn")) return;

    const btn = document.createElement("button");
    btn.id = "lc-sync-trigger-btn";
    btn.title = "Sync latest C++ Accepted Solution to LeetCode Community & GitHub";
    btn.innerHTML = `
      <svg width="18" height="18" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
        <polygon points="13 2 3 14 12 14 11 22 21 10 12 10 13 2"></polygon>
      </svg>
      <span>Sync Pipeline</span>
    `;

    btn.addEventListener("click", () => {
      sendSyncRequest();
    });

    document.body.appendChild(btn);
  }

  // Observe DOM for "Accepted" banner after code submission
  let lastAcceptedSlug = null;
  const observer = new MutationObserver((mutations) => {
    // Look for text matching "Accepted" in submission outcome headers
    const outcomeElements = document.querySelectorAll(
      '[data-e2e-locator="submission-result"], [class*="result__"], [class*="status-column__"]'
    );

    for (const el of outcomeElements) {
      if (el.innerText && el.innerText.includes("Accepted")) {
        const slug = getQuestionSlug();
        if (slug && slug !== lastAcceptedSlug) {
          lastAcceptedSlug = slug;
          console.log(`[LC-Sync] Detected Accepted submission for ${slug}`);
          showToast(`🎯 Accepted submission detected! Triggering pipeline...`, "success");
          sendSyncRequest();
          break;
        }
      }
    }
  });

  observer.observe(document.body, {
    childList: true,
    subtree: true,
  });

  // Inject UI once page is ready
  if (document.readyState === "loading") {
    document.addEventListener("DOMContentLoaded", injectActionButton);
  } else {
    injectActionButton();
  }
})();
