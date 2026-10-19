# 🚀 LeetCode Solutions & Community Editorials

An automated, recruiter-friendly repository of accepted LeetCode solutions in C++20 with in-depth algorithmic breakdowns, step-by-step intuition, complexity proofs, and synchronized LeetCode Community publications.

---

### 📊 Repository Statistics

| Total Solved | 🟢 Easy | 🟡 Medium | 🔴 Hard | Automation Engine |
| :---: | :---: | :---: | :---: | :---: |
| **0** | **0** | **0** | **0** | **Gemini 2.5 Flash + LeetCode UGC** |

---

### 📚 Problem Index

| # | Title | Solution | Difficulty | Topics | LeetCode Post |
| :-: | :-- | :-: | :-: | :-- | :-: |
| — | *No problems synchronized yet. Run `python main.py sync-recent` to start.* | — | — | — | — |

---

## 🛠️ Pipeline Architecture & How It Works

This repository is kept in sync using a zero-drift, single-shot pipeline:
1. **LeetCode GraphQL Fetcher:** Emulates Chrome TLS fingerprint (`curl_cffi` / JA3) to query accepted C++ submissions and problem metadata.
2. **Single-Shot Editorial Engine:** Grounded Gemini 2.5 Flash model produces canonical LeetCode UGC markdown, commented C++ code, and GitHub documentation in a single structured JSON response.
3. **UGC Publisher:** Automatically posts verified community solutions with strict anti-ban jitter cooldowns (`75s - 120s`).
4. **Local Git Sync:** Stages atomic commits directly without hitting GitHub Contents API secondary abuse limits.

*Automated with precision.*
