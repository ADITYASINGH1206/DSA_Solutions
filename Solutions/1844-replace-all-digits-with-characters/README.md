# [1844. Replace All Digits with Characters](https://leetcode.com/problems/replace-all-digits-with-characters/)
**Difficulty:** `Easy` | **Tags:** `string`

---

## Problem Description
You are given a **0-indexed** string `s` that has lowercase English letters in its **even** indices and digits in its **odd** indices.

You must perform an operation `shift(c, x)`, where `c` is a character and `x` is a digit, that returns the `xth` character after `c`.

* For example, `shift('a', 5) = 'f'` and `shift('x', 0) = 'x'`.

For every **odd** index `i`, you want to replace the digit `s[i]` with the result of the `shift(s[i-1], s[i])` operation.

Return `s`after replacing all digits. It is **guaranteed** that`shift(s[i-1], s[i])`will never exceed`'z'`.

**Note** that `shift(c, x)` is **not** a preloaded function, but an operation *to be implemented* as part of the solution.

**Example 1:**

```
Input: s = "a1c1e1"
Output: "abcdef"
Explanation: The digits are replaced as follows:
- s[1] -> shift('a',1) = 'b'
- s[3] -> shift('c',1) = 'd'
- s[5] -> shift('e',1) = 'f'
```

**Example 2:**

```
Input: s = "a1b2c3d4e"
Output: "abbdcfdhe"
Explanation: The digits are replaced as follows:
- s[1] -> shift('a',1) = 'b'
- s[3] -> shift('b',2) = 'd'
- s[5] -> shift('c',3) = 'f'
- s[7] -> shift('d',4) = 'h'
```

**Constraints:**

* `1 <= s.length <= 100`
* `s` consists only of lowercase English letters and digits.
* `shift(s[i-1], s[i]) <= 'z'` for all **odd** indices `i`.

---

## Solution & Editorial
# Intuition
The problem requires transforming digits at odd indices into characters based on their preceding character. Since the shift operation is simply an offset from the ASCII value of the preceding character, we can perform this transformation in a single pass.

# Approach
1. Iterate through the string `s` using an index `i` from `0` to `n-1`.
2. If `i` is even, the character is already a letter; append it directly to the result string `ans`.
3. If `i` is odd, the character is a digit. Calculate the new character by adding the integer value of the digit `(s[i] - '0')` to the previous character `s[i-1]`.
4. Append this calculated character to `ans`.

### Visual Trace (s = "a1c1")
| Index (i) | s[i] | Action | ans |
| :--- | :--- | :--- | :--- |
| 0 | 'a' | Append 'a' | "a" |
| 1 | '1' | 'a' + 1 = 'b' | "ab" |
| 2 | 'c' | Append 'c' | "abc" |
| 3 | '1' | 'c' + 1 = 'd' | "abcd" |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We traverse the string exactly once, performing constant-time arithmetic and string append operations.
- Space complexity: $$O(N)$$ to store the resulting string `ans`.

# Code
```cpp
class Solution {
public:
    string replaceDigits(string s) {
        int n = s.size();
        string ans = "";
        for(int i =0;i<n;i++){
            if(i%2==0) ans += s[i];
            else{
                s[i] = s[i-1] + (s[i]-'0');
                ans += s[i];
            }
        }
        return ans;
    }
};
```
