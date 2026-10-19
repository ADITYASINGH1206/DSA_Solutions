// Background service worker for LeetCode Sync Extension

const LOCAL_WEBHOOK_URL = "http://127.0.0.1:8765/api/sync-submission";

chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
  if (message.type === "TRIGGER_SYNC") {
    const { questionSlug, submissionId } = message.payload;
    console.log(`[LC-Sync] Forwarding submission to local daemon: ${questionSlug} (#${submissionId})`);

    fetch(LOCAL_WEBHOOK_URL, {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({
        questionSlug,
        submissionId: submissionId ? parseInt(submissionId, 10) : null,
      }),
    })
      .then(async (response) => {
        if (!response.ok) {
          throw new Error(`Local daemon returned status ${response.status}`);
        }
        const data = await response.json();
        sendResponse({ success: true, data });
      })
      .catch((error) => {
        console.error("[LC-Sync] Failed to reach local daemon:", error);
        sendResponse({
          success: false,
          error: "Could not connect to local daemon at http://127.0.0.1:8765. Make sure 'python main.py serve-webhook' is running.",
        });
      });

    return true; // Keep message channel open for asynchronous response
  }
});
