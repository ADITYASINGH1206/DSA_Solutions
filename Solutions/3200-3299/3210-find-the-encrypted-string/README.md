# [3210. Find the Encrypted String](https://leetcode.com/problems/find-the-encrypted-string/)
**Difficulty:** `Easy` | **Tags:** `string`

---

## Problem Description
You are given a string `s` and an integer `k`. Encrypt the string using the following algorithm:

* For each character `c` in `s`, replace `c` with the `kth` character after `c` in the string (in a cyclic manner).

Return the *encrypted string*.

**Example 1:**

**Input:** s = "dart", k = 3

**Output:** "tdar"

**Explanation:**

* For `i = 0`, the 3rd character after `'d'` is `'t'`.
* For `i = 1`, the 3rd character after `'a'` is `'d'`.
* For `i = 2`, the 3rd character after `'r'` is `'a'`.
* For `i = 3`, the 3rd character after `'t'` is `'r'`.

**Example 2:**

**Input:** s = "aaa", k = 1

**Output:** "aaa"

**Explanation:**

As all the characters are the same, the encrypted string will also be the same.

**Constraints:**

* `1 <= s.length <= 100`
* `1 <= k <= 104`
* `s` consists only of lowercase English letters.

---

## Solution & Editorial
# Intuition
The problem asks us to replace each character at index `i` with the character located `k` positions ahead in a cyclic manner. Since the string length is fixed, the "k-th character after index i" is simply the character at index `(i + k) % n`, where `n` is the length of the string.

# Approach
1. Calculate the length of the string `n`.
2. Iterate through each index `i` from `0` to `n-1`.
3. For each index, compute the target index using the formula `(i + k) % n` to handle the cyclic wrapping.
4. Append the character at the computed index to a result string `ans`.
5. Return the final string.

### Visual Trace (s = "dart", k = 3)
| i | Current Char | Target Index (i+3)%4 | Target Char | Result |
|---|---|---|---|---|
| 0 | 'd' | 3 | 't' | "t" |
| 1 | 'a' | 0 | 'd' | "td" |
| 2 | 'r' | 1 | 'a' | "tda" |
| 3 | 't' | 2 | 'r' | "tdar" |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We iterate through the string exactly once, performing constant-time arithmetic and string appending.
- Space complexity: $$O(N)$$, as we construct a new string of length $$N$$.

# Code
```cpp
class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ans = "";
        int n = s.size();
        for(int i = 0;i < n;i++){
            int place = (k + i) %n;
            char temp = s[place];
            ans += temp;
        }
        return ans;
    }
};
```
