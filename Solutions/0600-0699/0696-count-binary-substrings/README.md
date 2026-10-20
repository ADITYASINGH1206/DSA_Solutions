# [696. Count Binary Substrings](https://leetcode.com/problems/count-binary-substrings/)
**Difficulty:** `Easy` | **Tags:** `two-pointers`, `string`

---

## Problem Description
Given a binary string `s`, return the number of non-empty substrings that have the same number of `0`'s and `1`'s, and all the `0`'s and all the `1`'s in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

**Example 1:**

```
Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
```

**Example 2:**

```
Input: s = "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
```

**Constraints:**

* `1 <= s.length <= 105`
* `s[i]` is either `'0'` or `'1'`.

---

## Solution & Editorial
# Intuition
The problem asks us to count binary substrings that have an equal number of consecutive `0`s and `1`s. Instead of examining every possible substring, we can observe that valid substrings always occur at the boundary between two contiguous groups of identical characters (e.g., transitioning from a group of `0`s to a group of `1`s, or vice versa). For any adjacent pair of character groups with lengths `A` and `B`, we can form exactly `min(A, B)` valid binary substrings spanning across their boundary.

# Approach
1. Iterate through the string `s` using a pointer `i` to measure the lengths of consecutive identical characters.
2. For each group of identical characters starting at index `i`, count its length `cnt` using a inner `while` loop.
3. Store each group's length in a vector `t`.
4. After encoding the string into run-length segments stored in `t`, iterate from index `1` to `t.size() - 1` and accumulate `min(t[i - 1], t[i])` into `ans`.
5. Return `ans` as the total count of valid binary substrings.

### Visual Trace Walkthrough (Example 1: `s = "00110011"`)
- **Group Counting Phase:**
  - Starts at `i = 0`, group of `'0'`s has length `2`. `t` becomes `[2]`. Pointer `i` moves past this group.
  - Next group of `'1'`s has length `2`. `t` becomes `[2, 2]`.
  - Next group of `'0'`s has length `2`. `t` becomes `[2, 2, 2]`.
  - Final group of `'1'`s has length `2`. `t` becomes `[2, 2, 2, 2]`.
- **Accumulation Phase:**
  - `i = 1`: `min(t[0], t[1]) = min(2, 2) = 2`, `ans = 2`
  - `i = 2`: `min(t[1], t[2]) = min(2, 2) = 2`, `ans = 4`
  - `i = 3`: `min(t[2], t[3]) = min(2, 2) = 2`, `ans = 6`
- **Final Output:** `6`

# Complexity
- Time complexity: $$O(N)$$ — We traverse the string `s` of length $N$ once to compute run lengths, and then make a single pass over the frequency vector `t` of size at most $N$.
- Space complexity: $$O(N)$$ — In the worst-case scenario (e.g., alternating characters like `010101...`), the vector `t` stores up to $N$ run lengths.

# Code
```cpp
class Solution {
public:
    int countBinarySubstrings(string s) {
        int i = 0, n = s.size();
        vector<int> t;
        while (i < n) {
            int cnt = 1;
            while (i + 1 < n && s[i + 1] == s[i]) {
                ++cnt;
                ++i;
            }
            t.push_back(cnt);
            ++i;
        }
        int ans = 0;
        for (i = 1; i < t.size(); ++i) ans += min(t[i - 1], t[i]);
        return ans;
    }
};
```
