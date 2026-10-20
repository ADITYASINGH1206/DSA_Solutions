# [3794. Reverse String Prefix](https://leetcode.com/problems/reverse-string-prefix/)
**Difficulty:** `Easy` | **Tags:** `two-pointers`, `string`

---

## Problem Description
You are given a string `s` and an integer `k`.

Reverse the first `k` characters of `s` and return the resulting string.

**Example 1:**

**Input:** s = "abcd", k = 2

**Output:** "bacd"

**Explanation:**​​​​​​​

The first `k = 2` characters `"ab"` are reversed to `"ba"`. The final resulting string is `"bacd"`.

**Example 2:**

**Input:** s = "xyz", k = 3

**Output:** "zyx"

**Explanation:**

The first `k = 3` characters `"xyz"` are reversed to `"zyx"`. The final resulting string is `"zyx"`.

**Example 3:**

**Input:** s = "hey", k = 1

**Output:** "hey"

**Explanation:**

The first `k = 1` character `"h"` remains unchanged on reversal. The final resulting string is `"hey"`.

**Constraints:**

* `1 <= s.length <= 100`
* `s` consists of lowercase English letters.
* `1 <= k <= s.length`

---

## Solution & Editorial
# Intuition
To reverse the prefix of length `k`, we can isolate the substring from index `0` to `k-1`, reverse it, and then concatenate it with the remaining suffix of the string starting from index `k`.

# Approach
1. Extract the prefix of length `k` using `s.substr(0, k)`.
2. Apply the standard `std::reverse` algorithm to the extracted substring.
3. Concatenate the reversed prefix with the remainder of the original string obtained via `s.substr(k)`.

### Visual Trace (Example 1: s = "abcd", k = 2)
| Step | Operation | State |
| :--- | :--- | :--- |
| 1 | Initial | s = "abcd", k = 2 |
| 2 | Extract Prefix | t = "ab" |
| 3 | Reverse Prefix | t = "ba" |
| 4 | Concatenate | "ba" + "cd" = "bacd" |

# Complexity
- Time complexity: $$O(k)$$ — The substring extraction takes $$O(k)$$, the reversal takes $$O(k)$$, and the final concatenation takes $$O(n)$$, where $$n$$ is the length of the string. Since $$k \le n$$, the overall complexity is dominated by the string length.
- Space complexity: $$O(n)$$ — We create a new string to store the result, which requires space proportional to the length of the input string.

# Code
```cpp
class Solution {
public:
    string reversePrefix(string s, int k) {
        string t = s.substr(0, k);
        reverse(t.begin(), t.end());
        return t + s.substr(k);
    }
};
```
