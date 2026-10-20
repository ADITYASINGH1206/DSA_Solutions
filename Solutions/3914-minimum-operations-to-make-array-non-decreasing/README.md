# [3914. Minimum Operations to Make Array Non Decreasing](https://leetcode.com/problems/minimum-operations-to-make-array-non-decreasing/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`

---

## Problem Description
You are given an integer array `nums` of length `n`.

In one operation, you may choose any **subarray** `nums[l..r]` and **increase** each element in that **subarray** by `x`, where `x` is any **positive** integer.

Return the **minimum** possible **sum** of the values of `x` across all operations required to make the array **non-decreasing**.

An array is **non-decreasing** if `nums[i] <= nums[i + 1]` for all `0 <= i < n - 1`.

**Example 1:**

**Input:** nums = [3,3,2,1]

**Output:** 2

**Explanation:**

One optimal set of operations:

* Choose subarray `[2..3]` and add `x = 1` resulting in `[3, 3, 3, 2]`
* Choose subarray `[3..3]` and add `x = 1` resulting in `[3, 3, 3, 3]`

The array becomes non-decreasing, and the total sum of chosen `x` values is `1 + 1 = 2`.

**Example 2:**

**Input:** nums = [5,1,2,3]

**Output:** 4

**Explanation:**

One optimal set of operations:

* Choose subarray `[1..3]` and add `x = 4` resulting in `[5, 5, 6, 7]`

The array becomes non-decreasing, and the total sum of chosen `x` values is `4`.

**Constraints:**

* `1 <= n == nums.length <= 105`
* `1 <= nums[i] <= 109`

---

## Solution & Editorial
# Intuition
To make an array non-decreasing, every element `nums[i]` must be less than or equal to `nums[i+1]`. If we encounter a pair where `nums[i] > nums[i+1]`, the current element is "too large" relative to the next one. Since we can only increase elements, we must increase the suffix starting at `i+1` to at least match `nums[i]`. 

# Approach
1. Iterate through the array from index `0` to `n-2`.
2. For each pair `(nums[i], nums[i+1])`, if `nums[i] > nums[i+1]`, the difference `diff = nums[i] - nums[i+1]` represents the minimum amount we must add to the suffix starting at `i+1` to satisfy the non-decreasing condition at this specific index.
3. Accumulate these differences into a running total `ans`. Because we can always choose a subarray starting at `i+1` and extending to the end of the array, adding `diff` to this subarray effectively "lifts" the entire suffix, maintaining the relative order of subsequent elements while fixing the local violation.

### Visual Trace (nums = [3, 3, 2, 1])
| Index (i) | nums[i] | nums[i+1] | Violation? | Diff | ans |
|-----------|---------|-----------|------------|------|-----|
| 0         | 3       | 3         | No         | 0    | 0   |
| 1         | 3       | 2         | Yes        | 1    | 1   |
| 2         | 2       | 1         | Yes        | 1    | 2   |

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of the array, as we perform a single linear scan.
- Space complexity: $$O(1)$$ as we only use a single variable to track the total operations.

# Code
```cpp
class Solution {
public:
    long long minOperations(std::vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n-1; i++) {
            if (nums[i] > nums[i + 1]) {
                ans += (nums[i] - nums[i + 1]);
            }
        }
        
        return ans;
    }
};
```
