# [3471. Find the Largest Almost Missing Integer](https://leetcode.com/problems/find-the-largest-almost-missing-integer/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`

---

## Problem Description
You are given an integer array `nums` and an integer `k`.

An integer `x` is **almost missing** from `nums` if `x` appears in *exactly* one subarray of size `k` within `nums`.

Return the **largest** **almost missing** integer from `nums`. If no such integer exists, return `-1`.

A **subarray** is a contiguous sequence of elements within an array.

**Example 1:**

**Input:** nums = [3,9,2,1,7], k = 3

**Output:** 7

**Explanation:**

* 1 appears in 2 subarrays of size 3: `[9, 2, 1]` and `[2, 1, 7]`.
* 2 appears in 3 subarrays of size 3: `[3, 9, 2]`, `[9, 2, 1]`, `[2, 1, 7]`.
* 3 appears in 1 subarray of size 3: `[3, 9, 2]`.
* 7 appears in 1 subarray of size 3: `[2, 1, 7]`.
* 9 appears in 2 subarrays of size 3: `[3, 9, 2]`, and `[9, 2, 1]`.

We return 7 since it is the largest integer that appears in exactly one subarray of size `k`.

**Example 2:**

**Input:** nums = [3,9,7,2,1,7], k = 4

**Output:** 3

**Explanation:**

* 1 appears in 2 subarrays of size 4: `[9, 7, 2, 1]`, `[7, 2, 1, 7]`.
* 2 appears in 3 subarrays of size 4: `[3, 9, 7, 2]`, `[9, 7, 2, 1]`, `[7, 2, 1, 7]`.
* 3 appears in 1 subarray of size 4: `[3, 9, 7, 2]`.
* 7 appears in 3 subarrays of size 4: `[3, 9, 7, 2]`, `[9, 7, 2, 1]`, `[7, 2, 1, 7]`.
* 9 appears in 2 subarrays of size 4: `[3, 9, 7, 2]`, `[9, 7, 2, 1]`.

We return 3 since it is the largest and only integer that appears in exactly one subarray of size `k`.

**Example 3:**

**Input:** nums = [0,0], k = 1

**Output:** -1

**Explanation:**

There is no integer that appears in only one subarray of size 1.

**Constraints:**

* `1 <= nums.length <= 50`
* `0 <= nums[i] <= 50`
* `1 <= k <= nums.length`

---

## Solution & Editorial
# Intuition
An integer is "almost missing" if it appears in exactly one subarray of size `k`. For $1 < k < n$, an element can only appear in exactly one subarray if it is located at the very beginning or the very end of the array, and it does not appear anywhere else in the entire array. If $k=n$, the only subarray is the array itself, so we simply return the maximum element. If $k=1$, we return the largest element that appears exactly once in the array.

# Approach
1. Count the total frequency of every element in `nums` using a hash map `mp`.
2. Handle the edge case $k=n$: The entire array is the only subarray, so return the maximum element.
3. Handle the edge case $k=1$: Iterate through the array and return the largest element that has a frequency of 1.
4. For $1 < k < n$: An element $x$ can only be in exactly one subarray of size $k$ if it is at `nums[0]` or `nums[n-1]` and its total frequency in the array is 1. If an element is in the middle, it will inevitably be part of multiple subarrays of size $k$.

### Visual Trace (Example 1: nums = [3,9,2,1,7], k = 3)
- Total frequencies: {3:1, 9:1, 2:1, 1:1, 7:1}
- $k=3$ is not $n$ (5) and not 1.
- Check `nums[0]` (3) and `nums[4]` (7).
- Both have frequency 1. Return `max(3, 7) = 7`.

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the length of `nums`. We perform a single pass to count frequencies and a constant number of checks for the boundary conditions.
- Space complexity: $$O(N)$$ to store the frequency map of the elements.

# Code
```cpp
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            ++mp[nums[i]];
        }

        if (k == nums.size()) {
            return *max_element(nums.begin(), nums.end());
        }

        if (k == 1) {
            int maxValue = -1;

            for (int i = 0; i < n; i++) {
                if (mp[nums[i]] == 1 && nums[i] > maxValue) {
                    maxValue = nums[i];
                }
            }

            return maxValue;
        }

        n = n - 1;

        if (nums[0] == nums[n]) {
            return -1;
        }

        if (mp[nums[0]] == 1 && mp[nums[n]] == 1) {
            return max(nums[0], nums[n]);
        }

        if (mp[nums[0]] == 1 && mp[nums[n]] > 1) {
            return nums[0];
        }

        if (mp[nums[n]] == 1 && mp[nums[0]] > 1) {
            return nums[n];
        }

        return -1;
    }
};
```
