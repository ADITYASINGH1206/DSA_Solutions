# [977. Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/)
**Difficulty:** `Easy` | **Tags:** `array`, `two-pointers`, `sorting`

---

## Problem Description
Given an integer array `nums` sorted in **non-decreasing** order, return *an array of **the squares of each number** sorted in non-decreasing order*.

**Example 1:**

```
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
```

**Example 2:**

```
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
```

**Constraints:**

* `1 <= nums.length <= 104`
* `-104 <= nums[i] <= 104`
* `nums` is sorted in **non-decreasing** order.

**Follow up:** Squaring each element and sorting the new array is very trivial, could you find an `O(n)` solution using a different approach?

---

## Solution & Editorial
# Intuition
The array is already sorted in non-decreasing order. The largest squared values must originate from either the extreme left (negative numbers with large absolute values) or the extreme right (positive numbers with large absolute values). This naturally points to a two-pointer approach.

# Approach
1. Initialize a result vector `result` of size `n` and two pointers: `left` at index `0` and `right` at index `n - 1`.
2. Iterate backwards from `i = n - 1` down to `0` to populate the `result` array from largest to smallest.
3. At each step, compute the squares of the elements at `left` and `right`, stored in `left_s` and `right_s` respectively.
4. Compare `left_s` and `right_s`. Place the larger value into `result[i]` and increment `left` or decrement `right` accordingly.

### Visual Trace Walkthrough (Example 1: `nums = [-4, -1, 0, 3, 10]`)

| `i` | `left` | `right` | `nums[left]^2` | `nums[right]^2` | Action | `result` state |
|:---:|:---:|:---:|:---:|:---:|:---:|:---|
| 4 | 0 | 4 | 16 | 100 | `right_s > left_s`, right-- | `[_, _, _, _, 100]` |
| 3 | 0 | 3 | 16 | 9 | `left_s > right_s`, left++ | `[_, _, _, 16, 100]` |
| 2 | 1 | 3 | 1 | 9 | `right_s > left_s`, right-- | `[_, _, 9, 16, 100]` |
| 1 | 1 | 2 | 1 | 0 | `left_s > right_s`, left++ | `[_, 1, 9, 16, 100]` |
| 0 | 2 | 2 | 0 | 0 | `left_s <= right_s`, right-- | `[0, 1, 9, 16, 100]` |

# Complexity
- Time complexity: $$O(N)$$ — Each element is examined at most once by either the `left` or `right` pointer, resulting in a single pass of linear time.
- Space complexity: $$O(N)$$ — Auxiliary space required for the output array `result` of size `n`.

# Code
```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0;
        int right = n - 1;
        
        for (int i = n - 1; i >= 0; i--) {
            int left_s = nums[left] * nums[left];
            int right_s = nums[right] * nums[right];
            
            if (left_s > right_s) {
                result[i] = left_s;
                left++; 
            } else {
                result[i] = right_s;
                right--; 
            }
        }
        
        return result;
    }
};
```
