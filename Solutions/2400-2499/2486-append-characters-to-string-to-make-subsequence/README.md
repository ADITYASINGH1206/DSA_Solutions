# [2486. Append Characters to String to Make Subsequence](https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/)
**Difficulty:** `Medium` | **Tags:** `two-pointers`, `string`, `greedy`

---

## Problem Description
You are given two strings `s` and `t` consisting of only lowercase English letters.

Return *the minimum number of characters that need to be appended to the end of* `s` *so that* `t` *becomes a **subsequence** of* `s`.

A **subsequence** is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

**Example 1:**

```
Input: s = "coaching", t = "coding"
Output: 4
Explanation: Append the characters "ding" to the end of s so that s = "coachingding".
Now, t is a subsequence of s ("coachingding").
It can be shown that appending any 3 characters to the end of s will never make t a subsequence.
```

**Example 2:**

```
Input: s = "abcde", t = "a"
Output: 0
Explanation: t is already a subsequence of s ("abcde").
```

**Example 3:**

```
Input: s = "z", t = "abcde"
Output: 5
Explanation: Append the characters "abcde" to the end of s so that s = "zabcde".
Now, t is a subsequence of s ("zabcde").
It can be shown that appending any 4 characters to the end of s will never make t a subsequence.
```

**Constraints:**

* `1 <= s.length, t.length <= 105`
* `s` and `t` consist only of lowercase English letters.

---

## Solution & Editorial
# Intuition
To make `t` a subsequence of `s` by appending characters to the end of `s`, we need to find the longest prefix of `t` that is already a subsequence of `s`. Any characters in `t` that are not matched by this greedy traversal must be appended to `s`.

# Approach
1. Initialize two pointers, `si` for string `s` and `ti` for string `t`, both starting at 0.
2. Iterate through `s` using `si`. Whenever `s[si]` matches `t[ti]`, increment `ti` to look for the next character of `t`.
3. Always increment `si` to continue scanning `s`.
4. The number of characters remaining in `t` that were not matched is `t.length() - ti`. This is the minimum number of characters to append.

### Visual Trace (s = "coaching", t = "coding")
| si | s[si] | ti | t[ti] | Match? | Action |
|---|---|---|---|---|---|
| 0 | c | 0 | c | Yes | ti=1 |
| 1 | o | 1 | o | Yes | ti=2 |
| 2 | a | 2 | d | No | - |
| 3 | c | 2 | d | No | - |
| 4 | h | 2 | d | No | - |
| 5 | i | 2 | d | No | - |
| 6 | n | 2 | d | No | - |
| 7 | g | 2 | d | No | - |

Result: `m - ti` = 6 - 2 = 4.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of string `s`. We traverse `s` exactly once.
- Space complexity: $$O(1)$$, as we only use a few integer pointers regardless of input size.

# Code
```cpp
class Solution {
public:
    int appendCharacters(string s, string t) {
        int si = 0;
        int ti = 0;
        int n = s.length();
        int m = t.length();
    
        while (si < n && ti < m) {
            if (s[si] == t[ti]) {
                ti++;
            }
            si++;
        }
    
        return m - ti;
    }
};
```
