# [856. Score of Parentheses](https://leetcode.com/problems/score-of-parentheses/)
**Difficulty:** `Medium` | **Tags:** `string`, `stack`, `bracket-sequences`

---

## Problem Description
Given a balanced parentheses string `s`, return *the **score** of the string*.

The **score** of a balanced parentheses string is based on the following rule:

* `"()"` has score `1`.
* `AB` has score `A + B`, where `A` and `B` are balanced parentheses strings.
* `(A)` has score `2 * A`, where `A` is a balanced parentheses string.

**Example 1:**

```
Input: s = "()"
Output: 1
```

**Example 2:**

```
Input: s = "(())"
Output: 2
```

**Example 3:**

```
Input: s = "()()"
Output: 2
```

**Constraints:**

* `2 <= s.length <= 50`
* `s` consists of only `'('` and `')'`.
* `s` is a balanced parentheses string.

---

## Solution & Editorial
# Intuition
The problem asks us to compute the score of a balanced parentheses string under nested and sequential rules. Instead of maintaining an explicit stack to simulate nested expressions, we can track the nesting `depth` of each character. Every time we encounter the innermost core pair `()`, its contribution to the final score is determined entirely by its nesting depth as $2^{\text{depth} - 1}$, which translates efficiently to a bitshift operation `1 << depth`.

# Approach
1. Initialize two integer variables: `score` to accumulate the total score and `depth` to track the current nesting level of parentheses.
2. Iterate through each character of the string `s` using a loop index `i` from `0` to `s.size() - 1`.
3. If the character `s[i]` is `'('`, increment the `depth` by 1.
4. If the character `s[i]` is `')'`, decrement the `depth` by 1. Check if the preceding character `s[i - 1]` was `'('`. If it was, we have identified an atomic core pair `()`, so add `1 << depth` to the `score`.
5. After finishing the iteration, return the accumulated `score`.

### Visual Walkthrough for Example 2: `s = "(())"`
| Index `i` | Character `s[i]` | Action | `depth` | `score` update | Current `score` |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 0 | `(` | `++depth` | 1 | No | 0 |
| 1 | `(` | `++depth` | 2 | No | 0 |
| 2 | `)` | `--depth`, `s[i-1] == '('` | 1 | `score += (1 << 1) = 2` | 2 |
| 3 | `)` | `--depth`, `s[i-1] == ')'` | 0 | No | 2 |

# Complexity
- Time complexity: $$O(N)$$ — We iterate through the string of length $$N$$ exactly once, performing constant time $$O(1)$$ arithmetic and bitwise operations at each step.
- Space complexity: $$O(1)$$ — Only a few primitive integer variables are used, requiring no auxiliary heap memory or call stack space.

# Code
```cpp
class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0, depth = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++depth;
            } else {
                --depth;
                if (s[i - 1] == '(') {
                    score += 1 << depth;
                }
            }
        }
        return score;
    }
};
```
