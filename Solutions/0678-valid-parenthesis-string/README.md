# [678. Valid Parenthesis String](https://leetcode.com/problems/valid-parenthesis-string/)
**Difficulty:** `Medium` | **Tags:** `string`, `dynamic-programming`, `stack`, `greedy`, `bracket-sequences`

---

## Problem Description
Given a string `s` containing only three types of characters: `'('`, `')'` and `'*'`, return `true` *if* `s` *is **valid***.

The following rules define a **valid** string:

* Any left parenthesis `'('` must have a corresponding right parenthesis `')'`.
* Any right parenthesis `')'` must have a corresponding left parenthesis `'('`.
* Left parenthesis `'('` must go before the corresponding right parenthesis `')'`.
* `'*'` could be treated as a single right parenthesis `')'` or a single left parenthesis `'('` or an empty string `""`.

**Example 1:**

```
Input: s = "()"
Output: true
```

**Example 2:**

```
Input: s = "(*)"
Output: true
```

**Example 3:**

```
Input: s = "(*))"
Output: true
```

**Example 4:**

```
Input: s = "("
Output: false
```

**Constraints:**

* `1 <= s.length <= 100`
* `s[i]` is `'('`, `')'` or `'*'`.

---

## Solution & Editorial
# Intuition
To validate a parenthesis string containing wildcards (`*`), we must keep track of the possible range of open parentheses rather than a single exact count. Since `*` can act as `(`, `)`, or an empty string, it introduces a dynamic range of valid open bracket counts at every step.

# Approach
1. Maintain two counters, `min` and `max`, representing the minimum and maximum possible number of unmatched open parentheses `(`.
2. Iterate through each character `s[i]` of the string:
   - If `s[i] == '('`, both `min` and `max` are incremented.
   - If `s[i] == ')'`, both `min` and `max` are decremented.
   - If `s[i] == '*'`, `min` is decremented (treating `*` as `)`) and `max` is incremented (treating `*` as `(`).
3. Clamp `min` to `0` because the minimum number of open parentheses cannot drop below zero (we cannot have a negative balance of unmatched opens if extra closing brackets are ignored or cancelled).
4. If at any point `max < 0`, it means we have more closing brackets than total possible opening brackets and wildcards combined, so we immediately return `false`.
5. Finally, return `true` if `min == 0`, ensuring all open parentheses can be perfectly matched.

### Visual Trace Walkthrough (Example: `s = "(*)"`)
| Index `i` | Character `s[i]` | `min` before | `max` before | Action | `min` after | `max` after |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 0 | `(` | 0 | 0 | `min++, max++` | 1 | 1 |
| 1 | `*` | 1 | 1 | `min--, max++` | 0 | 2 |
| 2 | `)` | 0 | 2 | `min--, max--` | 0 | 1 |

At the end of the loop, `min == 0`, returning `true`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string `s`. We perform a single pass through the string with constant time operations per character.
- Space complexity: $$O(1)$$, as we only use a few integer variables (`min`, `max`, `n`, `i`) for our greedy tracking without allocating auxiliary data structures.

# Code
```cpp
class Solution {
public:
    bool checkValidString(string s) {
        int min = 0;
        int max = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                min++, max++;
            } else if (s[i] == ')') {
                min--, max--;
            } else {
                min--;
                max++;
            }
            if (min < 0)
                min = 0;
            if (max < 0)
                return false;
        }
        return (min == 0);
    }
};
```
