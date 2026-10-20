# [1784. Check if Binary String Has at Most One Segment of Ones](https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/)
**Difficulty:** `Easy` | **Tags:** `string`

---

## Problem Description
Given a binary string `s` **​​​​​without leading zeros**, return `true`​​​ *if* `s` *contains **at most one contiguous segment of ones***. Otherwise, return `false`.

**Example 1:**

```
Input: s = "1001"
Output: false
Explanation: The string has two segments of size 1.
```

**Example 2:**

```
Input: s = "110"
Output: true
```

**Constraints:**

* `1 <= s.length <= 100`
* `s[i]`​​​​ is either `'0'` or `'1'`.
* `s[0]` is `'1'`.

---

## Solution & Editorial
# Intuition
Since the string is guaranteed to start with '1' and contains no leading zeros, any occurrence of a '1' after a '0' implies the existence of a second segment. Therefore, the problem reduces to checking if the substring "01" exists anywhere in the string.

# Approach
1. The problem asks for at most one contiguous segment of ones.
2. Given the constraint that the string starts with '1', a second segment of ones can only begin if we encounter a '1' immediately following a '0'.
3. We use the `string::find` method to search for the pattern "01".
4. If `s.find("01")` returns `string::npos` (or -1), it means no second segment exists, and we return `true`. Otherwise, we return `false`.

### Visual Trace (s = "1001")
| Index | 0 | 1 | 2 | 3 |
|-------|---|---|---|---|
| Char  | 1 | 0 | 0 | 1 |

- `s.find("01")` starts at index 0.
- Index 1-2 is "00", no match.
- Index 2-3 is "01", match found at index 2.
- Result: `false`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string, as `find` performs a linear scan in the worst case.
- Space complexity: $$O(1)$$, as we use no extra auxiliary data structures.

# Code
```cpp
class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == -1;
    }
};
```
