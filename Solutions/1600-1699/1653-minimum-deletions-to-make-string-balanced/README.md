# [1653. Minimum Deletions to Make String Balanced](https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/)
**Difficulty:** `Medium` | **Tags:** `string`, `dynamic-programming`, `stack`

---

## Problem Description
You are given a string `s` consisting only of characters `'a'` and `'b'`​​​​.

You can delete any number of characters in `s` to make `s` **balanced**. `s` is **balanced** if there is no pair of indices `(i,j)` such that `i < j` and `s[i] = 'b'` and `s[j]= 'a'`.

Return *the **minimum** number of deletions needed to make* `s` ***balanced***.

**Example 1:**

```
Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
```

**Example 2:**

```
Input: s = "bbaaaaabb"
Output: 2
Explanation: The only solution is to delete the first two characters.
```

**Constraints:**

* `1 <= s.length <= 105`
* `s[i]` is `'a'` or `'b'`​​.

---

## Solution & Editorial
# Intuition
To make a string balanced, we must ensure no 'b' appears before an 'a'. This implies that at any point in the string, we have two choices when encountering an 'a': either delete the current 'a' (incrementing our deletion count) or delete all preceding 'b's encountered so far. By maintaining the count of 'b's seen, we can greedily decide the minimum cost at each step.

# Approach
1. Initialize `ans` to 0 (representing the minimum deletions) and `b` to 0 (the count of 'b's encountered so far).
2. Iterate through each character `c` in the string `s`:
   - If `c == 'b'`, increment the `b` counter.
   - If `c == 'a'`, we have two options to maintain balance: either delete this 'a' (cost: `ans + 1`) or delete all previously seen 'b's (cost: `b`). We update `ans` to the minimum of these two values.
3. Return `ans` after the loop completes.

### Visual Trace (s = "aababbab")
| Char | b count | ans (min(ans+1, b)) |
| :--- | :--- | :--- |
| 'a' | 0 | min(0+1, 0) = 0 |
| 'a' | 0 | min(0+1, 0) = 0 |
| 'b' | 1 | 0 |
| 'a' | 1 | min(0+1, 1) = 1 |
| 'b' | 2 | 1 |
| 'b' | 3 | 1 |
| 'a' | 3 | min(1+1, 3) = 2 |
| 'b' | 4 | 2 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string, as we perform a single pass over the input.
- Space complexity: $$O(1)$$, as we only use two integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0, b = 0;
        for (char& c : s) {
            if (c == 'b') {
                ++b;
            } else {
                ans = min(ans + 1, b);
            }
        }
        return ans;
    }
};
```
