# [3713. Longest Balanced Substring I](https://leetcode.com/problems/longest-balanced-substring-i/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `string`, `counting`, `enumeration`

---

## Problem Description
You are given a string `s` consisting of lowercase English letters.

A **substring** of `s` is called **balanced** if all **distinct** characters in the **substring** appear the **same** number of times.

Return the **length** of the **longest balanced substring** of `s`.

**Example 1:**

**Input:** s = "abbac"

**Output:** 4

**Explanation:**

The longest balanced substring is `"abba"` because both distinct characters `'a'` and `'b'` each appear exactly 2 times.

**Example 2:**

**Input:** s = "zzabccy"

**Output:** 4

**Explanation:**

The longest balanced substring is `"zabc"` because the distinct characters `'z'`, `'a'`, `'b'`, and `'c'` each appear exactly 1 time.​​​​​​​

**Example 3:**

**Input:** s = "aba"

**Output:** 2

**Explanation:**

**​​​​​​​**One of the longest balanced substrings is `"ab"` because both distinct characters `'a'` and `'b'` each appear exactly 1 time. Another longest balanced substring is `"ba"`.

**Constraints:**

* `1 <= s.length <= 1000`
* `s` consists of lowercase English letters.

---

## Solution & Editorial
# Intuition
A substring is balanced if every character present in it appears with the exact same frequency. Given the constraint $N \le 1000$, an $O(N^2)$ approach is optimal. We can iterate through every possible starting position of a substring and expand to the right, maintaining the frequency of each character and the number of distinct characters encountered.

# Approach
1. Iterate through every index `i` from $0$ to $n-1$ to serve as the start of a potential substring.
2. For each `i`, initialize a frequency array `cnt` of size 26 and variables `mx` (maximum frequency of any character) and `v` (number of distinct characters).
3. Expand the substring by iterating `j` from `i` to $n-1$. Update `cnt[s[j] - 'a']` and increment `v` if the character is new.
4. Track the maximum frequency `mx` encountered so far in the current window.
5. A substring is balanced if the product of the number of distinct characters `v` and the maximum frequency `mx` equals the length of the current substring (`j - i + 1`). If this condition holds, update `ans`.

### Visual Trace (s = "abbac")
| i | j | Substring | cnt | v | mx | mx * v == len | ans |
|---|---|---|---|---|---|---|---|
| 0 | 0 | "a" | {a:1} | 1 | 1 | 1*1 == 1 (Yes) | 1 |
| 0 | 1 | "ab" | {a:1, b:1} | 2 | 1 | 1*2 == 2 (Yes) | 2 |
| 0 | 2 | "abb" | {a:1, b:2} | 2 | 2 | 2*2 == 3 (No) | 2 |
| 0 | 3 | "abba" | {a:2, b:2} | 2 | 2 | 2*2 == 4 (Yes) | 4 |

# Complexity
- Time complexity: $$O(N^2)$$ where $N$ is the length of the string. We use nested loops to explore all possible substrings, and each inner update is $O(1)$.
- Space complexity: $$O(1)$$ as the frequency array `cnt` is fixed at size 26 regardless of input size.

# Code
```cpp
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        vector<int> cnt(26, 0);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            fill(cnt.begin(), cnt.end(), 0);
            int mx = 0, v = 0;
            for (int j = i; j < n; ++j) {
                int c = s[j] - 'a';
                if (++cnt[c] == 1) {
                    ++v;
                }
                mx = max(mx, cnt[c]);
                if (mx * v == j - i + 1) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
```
