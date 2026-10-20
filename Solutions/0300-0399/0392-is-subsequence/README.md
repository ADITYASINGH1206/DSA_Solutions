# [392. Is Subsequence](https://leetcode.com/problems/is-subsequence/)
**Difficulty:** `Easy` | **Tags:** `two-pointers`, `string`, `dynamic-programming`

---

## Problem Description
Given two strings `s` and `t`, return `true` *if* `s` *is a **subsequence** of* `t`*, or* `false` *otherwise*.

A **subsequence** of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., `"ace"` is a subsequence of `"abcde"` while `"aec"` is not).

**Example 1:**

```
Input: s = "abc", t = "ahbgdc"
Output: true
```

**Example 2:**

```
Input: s = "axc", t = "ahbgdc"
Output: false
```

**Constraints:**

* `0 <= s.length <= 100`
* `0 <= t.length <= 104`
* `s` and `t` consist only of lowercase English letters.

**Follow up:** Suppose there are lots of incoming `s`, say `s1, s2, ..., sk` where `k >= 109`, and you want to check one by one to see if `t` has its subsequence. In this scenario, how would you change your code?

---

## Solution & Editorial
# Intuition
We can determine if string `s` is a subsequence of string `t` by greedily matching characters of `s` sequentially within `t`. Using a single pointer to track the current expected character in `s`, we iterate through `t` from left to right, advancing our pointer whenever we find a match.

# Approach
1. Initialize a pointer `idx = 0` to track our current position in string `s`, and let `n = s.size()` be the target number of characters to match.
2. Iterate through each character of string `t` using a loop variable `i` from `0` to `t.size() - 1`.
3. Inside the loop, check if the current character `s[idx]` matches `t[i]`. If it does, increment `idx` to look for the next character of `s`.
4. Early exit by checking if `idx == n`. If we have successfully matched all characters of `s`, return `true` immediately.
5. After the loop terminates, return `idx == n` to handle cases where `s` is empty or matches on the final character.

### Visual Trace (Example 1: s = "abc", t = "ahbgdc")

| i | t[i] | idx (before) | s[idx] | Match? | idx (after) |
|---|------|--------------|--------|--------|-------------|
| 0 | 'a'  | 0            | 'a'    | Yes    | 1           |
| 1 | 'h'  | 1            | 'b'    | No     | 1           |
| 2 | 'b'  | 1            | 'b'    | Yes    | 2           |
| 3 | 'g'  | 2            | 'c'    | No     | 2           |
| 4 | 'd'  | 2            | 'c'    | No     | 2           |
| 5 | 'c'  | 2            | 'c'    | Yes    | 3 (Returns true) |

# Complexity
- Time complexity: $$O(|t|)$$ — In the worst-case scenario, we iterate through the entire string `t` once. Here `|t|` is the length of string `t`.
- Space complexity: $$O(1)$$ — We only use a few integer variables (`n`, `idx`, `i`), requiring constant auxiliary space.

# Code
```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int idx=0;
        for(int i = 0 ;i<t.size();i++){
            if(s[idx]==t[i]){
                idx++;
            }
            if(idx==n){
                return true;
            }
        }
        return idx==n;
    }
};
```
