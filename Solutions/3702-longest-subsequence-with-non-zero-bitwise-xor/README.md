# [3702. Longest Subsequence With Non-Zero Bitwise XOR](https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/)
**Difficulty:** `Medium` | **Tags:** `array`, `bit-manipulation`

---

## Problem Description
You are given an integer array `nums`.

Return the length of the **longest subsequence** in `nums` whose bitwise **XOR** is **non-zero**. If no such **subsequence** exists, return 0.

**Example 1:**

**Input:** nums = [1,2,3]

**Output:** 2

**Explanation:**

One longest subsequence is `[2, 3]`. The bitwise XOR is computed as `2 XOR 3 = 1`, which is non-zero.

**Example 2:**

**Input:** nums = [2,3,4]

**Output:** 3

**Explanation:**

The longest subsequence is `[2, 3, 4]`. The bitwise XOR is computed as `2 XOR 3 XOR 4 = 5`, which is non-zero.

**Constraints:**

* `1 <= nums.length <= 105`
* `0 <= nums[i] <= 109`

---

## Solution & Editorial
# Intuition
To find the longest subsequence with a non-zero XOR sum, we first consider the XOR sum of the entire array. If the total XOR sum is non-zero, the entire array is the longest subsequence. If the total XOR sum is zero, we must remove exactly one element to make the XOR sum non-zero, provided such an element exists.

# Approach
1. Calculate the total XOR sum (`tot`) of all elements in `nums` and track if there is at least one non-zero element (`nonZero`).
2. If `tot` is non-zero, the answer is the length of the array.
3. If `tot` is zero, we need to remove one element to make the XOR sum non-zero. If we remove an element `x`, the new XOR sum becomes `tot ^ x`. Since `tot` is 0, the new sum is `0 ^ x = x`. Thus, we need to remove an element `x` such that `x != 0`. If all elements are 0, no such subsequence exists.
4. The formula `nonZero * (nums.size() - !tot)` elegantly handles these cases: if `tot` is non-zero, `!tot` is 0, returning `nums.size()`. If `tot` is zero, `!tot` is 1, returning `nums.size() - 1` (if `nonZero` is true).

### Visual Trace (Example: [1, 2, 3])
| Iteration | n | tot (XOR) | nonZero |
|-----------|---|-----------|---------|
| 1 | 1 | 1 | 1 |
| 2 | 2 | 3 | 1 |
| 3 | 3 | 0 | 1 |
Result: `1 * (3 - 1) = 2`

# Complexity
- Time complexity: $$O(N)$$ where N is the length of the array, as we iterate through the input exactly once.
- Space complexity: $$O(1)$$ as we only use a few integer variables regardless of input size.

# Code
```cpp
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        auto tot = 0, nonZero = 0;

        for (auto& n : nums) {
            nonZero |= n > 0;
            tot ^= n;
        }

        return nonZero * (nums.size() - !tot);
    }
};
```
