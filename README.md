# LeetCode Solutions & Community Editorials

An automated repository of accepted LeetCode solutions in modern C++20 with algorithmic breakdowns, step-by-step intuition, complexity proofs, and synchronized LeetCode Community publications.

---

### Repository Statistics

| Total Solved | Easy | Medium | Hard | Automation Engine |
| :---: | :---: | :---: | :---: | :---: |
| **5** | **2** | **2** | **1** | **Gemini 2.5 Flash + LeetCode UGC** |

---

### Problem Index

| # | Title | Solution | Difficulty | Topics | LeetCode Post |
| :-: | :-- | :-: | :-: | :-- | :-: |
| 0001 | [Two Sum](https://leetcode.com/problems/two-sum/) | [C++](./Solutions/0000-0099/1.Two Sum/solution.cpp) | `Easy` | `c`, `array`, `hash-table` | [Editorial](https://leetcode.com/problems/two-sum/solutions/one-pass-hash-table-on-time-on-space-c20-5etk/) |
| 0003 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | [C++](./Solutions/0000-0099/3. Longest Substring Without Repeating Characters/solution.cpp) | `Medium` | `c`, `hash-table`, `string` | [Editorial](https://leetcode.com/problems/longest-substring-without-repeating-characters/solutions/sliding-window-with-hash-map-on-time-omi-gjks/) |
| 0004 | [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) | [C++](./Solutions/0004-median-of-two-sorted-arrays/solution.cpp) | `Hard` | `c`, `array`, `binary-search` | — |
| 0007 | [Reverse Integer](https://leetcode.com/problems/reverse-integer/) | [C++](./Solutions/0007-reverse-integer/solution.cpp) | `Medium` | `c`, `math` | — |
| 2089 | [Find Target Indices After Sorting Array](https://leetcode.com/problems/find-target-indices-after-sorting-array/) | [C++](./Solutions/2089-find-target-indices-after-sorting-array/solution.cpp) | `Easy` | `c`, `array`, `binary-search` | [Community Post](https://leetcode.com/problems/find-target-indices-after-sorting-array/solutions/) |

---

## Pipeline Architecture & How It Works

This repository is kept in sync using a zero-drift, single-shot pipeline:
1. **LeetCode GraphQL Fetcher:** Emulates Chrome TLS fingerprint (`curl_cffi` / JA3) to query accepted C++ submissions and problem metadata.
2. **Single-Shot Editorial Engine:** Grounded Gemini 2.5 Flash model produces canonical LeetCode UGC markdown, commented C++ code, and GitHub documentation in a single structured JSON response.
3. **UGC Publisher:** Automatically posts verified community solutions with strict anti-ban jitter cooldowns (75s - 120s).
4. **Pull Request Workflow:** Solutions are grouped into batches of 10 per Pull Request, creating isolated Git branches and opening PRs automatically via the GitHub CLI.
