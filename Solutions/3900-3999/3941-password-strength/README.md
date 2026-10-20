# [3941. Password Strength](https://leetcode.com/problems/password-strength/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `string`

---

## Problem Description
You are given a string `password`.

The **strength** of the password is calculated based on the following rules:

* 1 point for each distinct lowercase letter (`'a'` to `'z'`).
* 2 points for each distinct uppercase letter (`'A'` to `'Z'`).
* 3 points for each distinct digit (`'0'` to `'9'`).
* 5 points for each distinct special character from the set `"!@#$"`.

Each character contributes **at most** once, even if it appears multiple times.

Return an integer denoting the strength of the password.

**Example 1:**

**Input:** password = "aA1!"

**Output:** 11

**Explanation:**

* The distinct characters are `'a'`, `'A'`, `'1'` and `'!'`.
* Thus, the `strength = 1 + 2 + 3 + 5 = 11`.

**Example 2:**

**Input:** password = "bbB11#"

**Output:** 11

**Explanation:**

* The distinct characters are `'b'`, `'B'`, `'1'` and `'#'`.
* Thus, the `strength = 1 + 2 + 3 + 5 = 11`.​​​​​​​

**Constraints:**

* `1 <= password.length <= 105`
* `password` consists of lowercase and uppercase English letters, digits, and special characters from `"!@#$"`.

---

## Solution & Editorial
# Intuition
The problem requires counting the contribution of each *distinct* character in a string based on predefined categories. Since each character type contributes exactly once regardless of frequency, we can use a boolean array to track which characters have already been processed, ensuring each unique character is counted only once.

# Approach
1. Initialize a boolean array `seen` of size 256 to track encountered characters, initialized to `false`.
2. Iterate through each character `c` in the input string `password`.
3. If `seen[c]` is `false`, it is the first time we have encountered this character:
   - Mark `seen[c]` as `true`.
   - Check the character category using conditional logic:
     - Lowercase ('a'-'z'): Add 1 to `strength`.
     - Uppercase ('A'-'Z'): Add 2 to `strength`.
     - Digits ('0'-'9'): Add 3 to `strength`.
     - Special ('!', '@', '#', '$'): Add 5 to `strength`.
4. Return the accumulated `strength`.

### Visual Trace (Example 1: "aA1!")
| Iteration | Char | Seen? | Action | Strength |
|-----------|------|-------|--------|----------|
| 1         | 'a'  | No    | Add 1  | 1        |
| 2         | 'A'  | No    | Add 2  | 3        |
| 3         | '1'  | No    | Add 3  | 6        |
| 4         | '!'  | No    | Add 5  | 11       |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the password. We iterate through the string exactly once, and each character lookup/update in the boolean array is $$O(1)$$.
- Space complexity: $$O(1)$$, as the `seen` array is of fixed size 256, which does not scale with the input size.

# Code
```cpp
class Solution {
public:
    int passwordStrength(string password) {
        bool seen[256] = {false}; 
        int strength = 0;
        
        for (char c : password) {
            if (!seen[c]) {
                seen[c] = true;
                if (c >= 'a' && c <= 'z') {
                    strength += 1;
                } else if (c >= 'A' && c <= 'Z') {
                    strength += 2;
                } else if (c >= '0' && c <= '9') {
                    strength += 3;
                } else if (c == '!' || c == '@' || c == '#' || c == '$') {
                    strength += 5;
                }
            }
        }
        
        return strength;
    }
};
```
