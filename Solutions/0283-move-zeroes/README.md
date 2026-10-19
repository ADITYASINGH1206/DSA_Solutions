# [283. Move Zeroes](https://leetcode.com/problems/move-zeroes/)
**Difficulty:** `Easy` | **Tags:** `array`, `two-pointers`

---

## Problem Description
Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

**Note** that you must do this in-place without making a copy of the array.

**Example 1:**

```
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
```

**Example 2:**

```
Input: nums = [0]
Output: [0]
```

**Constraints:**

* `1 <= nums.length <= 104`
* `-231 <= nums[i] <= 231 - 1`

**Follow up:** Could you minimize the total number of operations done?

---

## Solution & Editorial
# Intuition
The problem requires moving all zeros to the end of the array while preserving the relative order of non-zero elements, all in-place. We can achieve this efficiently by utilizing a two-pointer approach where one pointer scans the array and the other tracks the insertion index for non-zero elements.

# Approach
1. Initialize a pointer `k` to 0, which points to the next available position to place a non-zero element. Obtain the size of the array `n = nums.size()`.
2. Iterate through the array using a loop variable `i` from `0` to `n - 1`.
3. Check if the current element `nums[i]` is non-zero (`if (nums[i])`). If it is non-zero, swap `nums[i]` with `nums[k]` and increment `k`.
4. If `nums[i]` is zero, simply advance `i` while leaving `k` stationary, effectively holding the position for the next non-zero element.

### Visual Dry Run (Example 1: `nums = [0, 1, 0, 3, 12]`)
- Initial: `k = 0`, `n = 5`, `nums = [0, 1, 0, 3, 12]`
- `i = 0`: `nums[0] = 0` (Zero, do nothing) -> `nums = [0, 1, 0, 3, 12]`, `k = 0`
- `i = 1`: `nums[1] = 1` (Non-zero, swap `nums[1]` and `nums[0]`, `k` becomes 1) -> `nums = [1, 0, 0, 3, 12]`, `k = 1`
- `i = 2`: `nums[2] = 0` (Zero, do nothing) -> `nums = [1, 0, 0, 3, 12]`, `k = 1`
- `i = 3`: `nums[3] = 3` (Non-zero, swap `nums[3]` and `nums[1]`, `k` becomes 2) -> `nums = [1, 3, 0, 0, 12]`, `k = 2`
- `i = 4`: `nums[4] = 12` (Non-zero, swap `nums[4]` and `nums[2]`, `k` becomes 3) -> `nums = [1, 3, 12, 0, 0]`, `k = 3`

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of elements in `nums`. We traverse the array exactly once with the single loop.
- Space complexity: $$O(1)$$, as all operations are performed in-place using a constant amount of extra memory.

# Code
```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i]) {
                swap(nums[i], nums[k++]);
            }
        }
    }
};
```
