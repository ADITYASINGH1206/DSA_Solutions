# [3090. Maximum Length Substring With Two Occurrences](https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `string`, `sliding-window`

---

## Problem Description
Given a string `s`, return the **maximum** length of a substring such that it contains *at most two occurrences* of each character.

**Example 1:**

**Input:** s = "bcbbbcba"

**Output:** 4

**Explanation:**

The following substring has a length of 4 and contains at most two occurrences of each character: `"bcbbbcba"`.

**Example 2:**

**Input:** s = "aaaa"

**Output:** 2

**Explanation:**

The following substring has a length of 2 and contains at most two occurrences of each character: `"aaaa"`.

**Constraints:**

* `2 <= s.length <= 100`
* `s` consists only of lowercase English letters.

---

## Solution & Editorial
# Intuition
To find the longest substring with at most two occurrences of any character, we can maintain a sliding window `[i, j]` that expands to the right. Whenever a character count exceeds two, we shrink the window from the left until the constraint is satisfied again.

# Approach
1. Initialize a frequency map `m` to track character counts, a left pointer `i = 0`, and a result variable `res = 0`.
2. Iterate with a right pointer `j` from `0` to `n-1`:
   - Increment the count of `s[j]` in `m`.
   - While `m[s[j]] > 2`, decrement the count of `s[i]` and increment `i` to shrink the window.
   - Update `res` with the maximum window size `j - i + 1`.

### Visual Trace (s = "bcbb")
| j | s[j] | m[s[j]] | i | Window | res |
|---|---|---|---|---|---|
| 0 | b | 1 | 0 | "b" | 1 |
| 1 | c | 1 | 0 | "bc" | 2 |
| 2 | b | 2 | 0 | "bcb" | 3 |
| 3 | b | 3 | 0 | "bcbb" -> "cbb" | 3 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. Each character is added and removed from the window at most once.
- Space complexity: $$O(1)$$, as the map stores at most 26 lowercase English letters regardless of input size.

# Code
```cpp
class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> m;
        int i = 0, j = 0, n = s.size();
        int res = 0;    
        while (j < n) {
            m[s[j]]++;
            while (m[s[j]] > 2) {
                m[s[i]]--;
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};
```
