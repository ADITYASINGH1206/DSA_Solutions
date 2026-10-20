# [1021. Remove Outermost Parentheses](https://leetcode.com/problems/remove-outermost-parentheses/)
**Difficulty:** `Easy` | **Tags:** `string`, `stack`, `bracket-sequences`

---

## Problem Description
A valid parentheses string is either empty `""`, `"(" + A + ")"`, or `A + B`, where `A` and `B` are valid parentheses strings, and `+` represents string concatenation.

* For example, `""`, `"()"`, `"(())()"`, and `"(()(()))"` are all valid parentheses strings.

A valid parentheses string `s` is primitive if it is nonempty, and there does not exist a way to split it into `s = A + B`, with `A` and `B` nonempty valid parentheses strings.

Given a valid parentheses string `s`, consider its primitive decomposition: `s = P1 + P2 + ... + Pk`, where `Pi` are primitive valid parentheses strings.

Return `s` *after removing the outermost parentheses of every primitive string in the primitive decomposition of* `s`.

**Example 1:**

```
Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
```

**Example 2:**

```
Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
```

**Example 3:**

```
Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".
```

**Constraints:**

* `1 <= s.length <= 105`
* `s[i]` is either `'('` or `')'`.
* `s` is a valid parentheses string.

---

## Solution & Editorial
# Intuition
To remove the outermost parentheses of every primitive component in a valid parentheses string, we can track the nesting level of parentheses using a counter. Since any primitive component starts with an outer '(' and ends with its matching ')', we only need to append characters to our result when they reside strictly inside a primitive block (i.e., not at the outermost boundaries).

# Approach
1. Initialize an empty result string `ans` and an integer `opened` to keep track of the current nesting depth.
2. Iterate through each character `c` in the input string `s`:
   - If `c == '('`: check if `opened > 0`. If true, this '(' is not the outermost opening parenthesis of the current primitive component, so we append it to `ans`. Then, increment `opened`.
   - If `c == ')'`: decrement `opened` first. If `opened > 1` before decrementing (or equivalently `opened > 0` after or checking `opened > 1` during), this ')' is not the outermost closing parenthesis, so we append it to `ans`.
3. Return the accumulated string `ans`.

### Visual Walkthrough (Example 1: `s = "(()())(())"`)

| Character | `opened` (Before) | Action | `opened` (After) | `ans` | Explanation |
| :---: | :---: | :--- | :---: | :--- | :--- |
| `(` | 0 | `opened == 0`, skip | 1 | `""` | Outer '(' of first primitive |
| `(` | 1 | `opened > 0`, append | 2 | `"("` | Inner '(' |
| `)` | 2 | `opened > 1`, append | 1 | `"()"` | Inner ')' |
| `(` | 1 | `opened > 0`, append | 2 | `"()("` | Inner '(' |
| `)` | 2 | `opened > 1`, append | 1 | `"()()"` | Inner ')' |
| `)` | 1 | `opened == 1`, skip | 0 | `"()()"` | Outer ')' of first primitive |
| `(` | 0 | `opened == 0`, skip | 1 | `"()()"` | Outer '(' of second primitive |
| `(` | 1 | `opened > 0`, append | 2 | `"()()("` | Inner '(' |
| `)` | 2 | `opened > 1`, append | 1 | `"()()()"` | Inner ')' |
| `)` | 1 | `opened == 1`, skip | 0 | `"()()()"` | Outer ')' of second primitive |

# Complexity
- Time complexity: $$O(N)$$ — We iterate through the string of length $$N$$ exactly once, performing constant time $$O(1)$$ operations at each character.
- Space complexity: $$O(N)$$ — Auxiliary space required for the output string `ans` in the worst case proportional to the input length.

# Code
```cpp
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int opened = 0;
        
        for (char c : s) {
            if (c == '(') {
                if (opened > 0) ans += c;
                opened++;
            } else {
                if (opened > 1) ans += c;
                opened--;
            }
        }
        
        return ans;
    }
};
```
