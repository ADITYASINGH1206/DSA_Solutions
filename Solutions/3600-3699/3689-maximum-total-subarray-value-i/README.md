# [3689. Maximum Total Subarray Value I](https://leetcode.com/problems/maximum-total-subarray-value-i/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`

---

## Problem Description
You are given an integer array `nums` of length `n` and an integer `k`.

You need to choose **exactly** `k` non-empty subarrays `nums[l..r]` of `nums`. Subarrays may overlap, and the exact same subarray (same `l` and `r`) **can** be chosen more than once.

The **value** of a subarray `nums[l..r]` is defined as: `max(nums[l..r]) - min(nums[l..r])`.

The **total value** is the sum of the **values** of all chosen subarrays.

Return the **maximum** possible total value you can achieve.

**Example 1:**

**Input:** nums = [1,3,2], k = 2

**Output:** 4

**Explanation:**

One optimal approach is:

* Choose `nums[0..1] = [1, 3]`. The maximum is 3 and the minimum is 1, giving a value of `3 - 1 = 2`.
* Choose `nums[0..2] = [1, 3, 2]`. The maximum is still 3 and the minimum is still 1, so the value is also `3 - 1 = 2`.

Adding these gives `2 + 2 = 4`.

**Example 2:**

**Input:** nums = [4,2,5,1], k = 3

**Output:** 12

**Explanation:**

One optimal approach is:

* Choose `nums[0..3] = [4, 2, 5, 1]`. The maximum is 5 and the minimum is 1, giving a value of `5 - 1 = 4`.
* Choose `nums[0..3] = [4, 2, 5, 1]`. The maximum is 5 and the minimum is 1, so the value is also `4`.
* Choose `nums[2..3] = [5, 1]`. The maximum is 5 and the minimum is 1, so the value is again `4`.

Adding these gives `4 + 4 + 4 = 12`.

**Constraints:**

* `1 <= n == nums.length <= 5 * 10​​​​​​​4`
* `0 <= nums[i] <= 109`
* `1 <= k <= 105`

---

## Solution & Editorial
# Intuition
The problem asks us to maximize the sum of `max(subarray) - min(subarray)` for exactly `k` subarrays. Since we can choose the same subarray multiple times and subarrays can overlap, we should identify the subarray that yields the largest possible value across the entire array. This value is simply the difference between the global maximum and the global minimum of the input array.

# Approach
1. Observe that for any subarray `nums[l..r]`, its value `max(nums[l..r]) - min(nums[l..r])` is bounded by `global_max - global_min`.
2. Since we can choose the same subarray multiple times, we can simply pick the subarray that contains both the global maximum and the global minimum `k` times.
3. Use `std::minmax_element` to find the global minimum and maximum in a single pass.
4. Calculate the result as `k * (global_max - global_min)`.

### Visual Trace (Example 2: nums = [4, 2, 5, 1], k = 3)
- Global Max: 5
- Global Min: 1
- Max Value per subarray: 5 - 1 = 4
- Total Value: 3 * 4 = 12

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of the array, as we perform a single linear scan to find the min and max elements.
- Space complexity: $$O(1)$$ as we only store the pointers to the min and max elements.

# Code
```cpp
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        auto [mini, maxi] = minmax_element(nums.begin(), nums.end());
        return 1LL * k * (*maxi - *mini);
    }
};
```
