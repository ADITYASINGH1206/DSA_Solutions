# [561. Array Partition](https://leetcode.com/problems/array-partition/)
**Difficulty:** `Easy` | **Tags:** `array`, `greedy`, `sorting`, `counting-sort`

---

## Problem Description
Given an integer array `nums` of `2n` integers, group these integers into `n` pairs `(a1, b1), (a2, b2), ..., (an, bn)` such that the sum of `min(ai, bi)` for all `i` is **maximized**. Return *the maximized sum*.

**Example 1:**

```
Input: nums = [1,4,3,2]
Output: 4
Explanation: All possible pairings (ignoring the ordering of elements) are:
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4.
```

**Example 2:**

```
Input: nums = [6,2,6,5,1,2]
Output: 9
Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.
```

**Constraints:**

* `1 <= n <= 104`
* `nums.length == 2 * n`
* `-104 <= nums[i] <= 104`

---

## Solution & Editorial
# Intuition
To maximize the sum of minimums from paired elements, we should pair numbers that are as close to each other as possible. If we sort the array in ascending order, pairing adjacent elements ensures that the difference between paired numbers is minimized, which consequently maximizes the sum of their minimums.

# Approach
1. Sort the input vector `nums` in ascending order using `sort(nums.begin(), nums.end())`.
2. Initialize an accumulator variable `ans` to `0`.
3. Iterate through the sorted array with a step of 2 (`i += 2`).
4. At each step, add `min(nums[i], nums[i + 1])` to `ans`. Since the array is sorted, `nums[i]` is always less than or equal to `nums[i + 1]`, making `nums[i]` the minimum.
5. Return `ans` after the loop completes.

### Visual Trace Walkthrough (Example 1: `nums = [1, 4, 3, 2]`)
- **Initial Array**: `[1, 4, 3, 2]`
- **Sorted Array**: `[1, 2, 3, 4]`

| Iteration | `i` | `nums[i]` | `nums[i+1]` | `min(nums[i], nums[i+1])` | `ans` (Cumulative) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | `0` | `1` | `2` | `1` | `1` |
| 2 | `2` | `3` | `4` | `3` | `4` |

- **Final Output**: `4`

# Complexity
- Time complexity: $$O(N \log N)$$ — dominated by the sorting step of the `nums` array of size $$N$$, where $$N = 2n$$. The subsequent linear scan takes $$O(N)$$ time.
- Space complexity: $$O(1)$$ auxiliary space, or $$O(\log N)$$ depending on the underlying sorting stack implementation.

# Code
```cpp
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i+=2){
            ans+=min(nums[i],nums[i+1]);
        }
        return ans;
    }
};
```
