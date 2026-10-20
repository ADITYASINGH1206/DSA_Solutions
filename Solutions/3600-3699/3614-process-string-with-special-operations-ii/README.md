# [3614. Process String with Special Operations II](https://leetcode.com/problems/process-string-with-special-operations-ii/)
**Difficulty:** `Hard` | **Tags:** `string`, `simulation`

---

## Problem Description
You are given a string `s` consisting of lowercase English letters and the special characters: `'*'`, `'#'`, and `'%'`.

You are also given an integer `k`.

Build a new string `result` by processing `s` according to the following rules from left to right:

* If the letter is a **lowercase** English letter append it to `result`.
* A `'*'` **removes** the last character from `result`, if it exists.
* A `'#'` **duplicates** the current `result` and **appends** it to itself.
* A `'%'` **reverses** the current `result`.

Return the `kth` character of the final string `result`. If `k` is out of the bounds of `result`, return `'.'`.

**Example 1:**

**Input:** s = "a#b%\*", k = 1

**Output:** "a"

**Explanation:**

| `i` | `s[i]` | Operation | Current `result` |
| --- | --- | --- | --- |
| 0 | `'a'` | Append `'a'` | `"a"` |
| 1 | `'#'` | Duplicate `result` | `"aa"` |
| 2 | `'b'` | Append `'b'` | `"aab"` |
| 3 | `'%'` | Reverse `result` | `"baa"` |
| 4 | `'*'` | Remove the last character | `"ba"` |

The final `result` is `"ba"`. The character at index `k = 1` is `'a'`.

**Example 2:**

**Input:** s = "cd%#\*#", k = 3

**Output:** "d"

**Explanation:**

| `i` | `s[i]` | Operation | Current `result` |
| --- | --- | --- | --- |
| 0 | `'c'` | Append `'c'` | `"c"` |
| 1 | `'d'` | Append `'d'` | `"cd"` |
| 2 | `'%'` | Reverse `result` | `"dc"` |
| 3 | `'#'` | Duplicate `result` | `"dcdc"` |
| 4 | `'*'` | Remove the last character | `"dcd"` |
| 5 | `'#'` | Duplicate `result` | `"dcddcd"` |

The final `result` is `"dcddcd"`. The character at index `k = 3` is `'d'`.

**Example 3:**

**Input:** s = "z\*#", k = 0

**Output:** "."

**Explanation:**

| `i` | `s[i]` | Operation | Current `result` |
| --- | --- | --- | --- |
| 0 | `'z'` | Append `'z'` | `"z"` |
| 1 | `'*'` | Remove the last character | `""` |
| 2 | `'#'` | Duplicate the string | `""` |

The final `result` is `""`. Since index `k = 0` is out of bounds, the output is `'.'`.

**Constraints:**

* `1 <= s.length <= 105`
* `s` consists of only lowercase English letters and special characters `'*'`, `'#'`, and `'%'`.
* `0 <= k <= 1015`
* The length of `result` after processing `s` will not exceed `1015`.

---

## Solution & Editorial
# Intuition
The problem asks for the $k$-th character of a string after a series of operations. Since the final string length can be up to $10^{15}$, we cannot construct the string explicitly. Instead, we observe that the operations are reversible. By first calculating the final length of the string, we can work backward from the end of the input string `s` to determine which character ends up at index `k`.

# Approach
1. **Forward Pass**: Calculate the final length `len` of the string by simulating the operations. For each character:
   - Lowercase letter: `len++`
   - `'*'`: `len = max(len - 1, 0LL)`
   - `'#'`: `len *= 2`
   - `'%'`: `len` remains unchanged.
2. **Backward Pass**: Starting from the end of `s`, trace the index `k` back to its original position:
   - If `s[i]` is a letter: If `len == k + 1`, the current character is our answer. Otherwise, `len--`.
   - If `s[i]` is `'*'`: The character was removed, so we increment `len` to account for the character that existed before the removal.
   - If `s[i]` is `'#'`: The string was doubled. If `k >= len / 2`, the character was in the second half, so we subtract `len / 2` from `k`. Then `len /= 2`.
   - If `s[i]` is `'%'`: The string was reversed, so we update `k = len - 1 - k`.

### Visual Trace (Example 2: s = "cd%#*#", k = 3)
| Step | Op | len | k | Action |
| :--- | :--- | :--- | :--- | :--- |
| Start | - | 6 | 3 | - |
| i=5 | '#' | 6 | 3 | k >= 3, k=0, len=3 |
| i=4 | '*' | 3 | 0 | len=4 |
| i=3 | '#' | 4 | 0 | k < 2, len=2 |
| i=2 | '%' | 2 | 1 | k = 2-1-1 = 0 |
| i=1 | 'd' | 2 | 0 | len=2 != k+1, len=1 |
| i=0 | 'c' | 1 | 0 | len=1 == k+1, return 'd' |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string `s`. We perform two linear passes over the input string.
- Space complexity: $$O(N)$$ to store the input string, with $O(1)$ auxiliary space for variables.

# Code
```cpp
class Solution {
    typedef long long ll;
public:
    char processStr(string s, ll k) {
        int n = s.size();
        ll len = 0;

        for (auto& ch : s) {
            if (ch == '*')
                len = max(len - 1, 0LL);
            else if (ch == '#')
                len *= 2;
            else if (ch != '%')
                len++;
        }

        if (k >= len) return '.';

        for (int i = n - 1;; i--) {
            switch (s[i]) {
            case '*':
                len++;
                break;
            case '#':
                if (k >= len / 2)
                    k -= len / 2;
                len /= 2;
                break;
            case '%':
                k = len - 1 - k;
                break;
            default:
                if (len == k + 1)
                    return s[i];
                len--;
            }
        }
    }
};
```
