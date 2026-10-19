# [44. Wildcard Matching](https://leetcode.com/problems/wildcard-matching/)
**Difficulty:** `Hard` | **Tags:** `string`, `dynamic-programming`, `greedy`, `recursion`

---

## Problem Description
Given an input string (`s`) and a pattern (`p`), implement wildcard pattern matching with support for `'?'` and `'*'` where:

* `'?'` Matches any single character.
* `'*'` Matches any sequence of characters (including the empty sequence).

The matching should cover the **entire** input string (not partial).

**Example 1:**

```
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

**Example 2:**

```
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
```

**Example 3:**

```
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
```

**Constraints:**

* `0 <= s.length, p.length <= 2000`
* `s` contains only lowercase English letters.
* `p` contains only lowercase English letters, `'?'` or `'*'`.

---

## Solution & Editorial
# Intuition
The problem requires matching a string `s` against a pattern `p` containing wildcard characters `?` and `*`. While dynamic programming or recursion can solve this, an optimal greedy approach using pointers tracks the last seen `*` token. This allows us to backtrack efficiently without exploring redundant states, achieving optimal linear time complexity and constant auxiliary space.

# Code
```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int si = 0, pi = 0, match = 0, star = -1;
        int sn = s.length(), pn = p.length();
        while (si < sn) {
            if (pi < pn && (p[pi] == '?' || p[pi] == s[si])) {
                si++;
                pi++;
            } else if (pi < pn && p[pi] == '*') {
                star = pi;
                match = si;
                pi++;
            } else if (star != -1) {
                pi = star + 1;
                match++;
                si = match;
            } else {
                return false;
            }
        }
        while (pi < pn && p[pi] == '*') {
            pi++;
        }
        return pi == pn;
    }
};
```
