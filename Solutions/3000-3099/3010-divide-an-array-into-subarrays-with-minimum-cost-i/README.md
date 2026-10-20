# [3010. Divide an Array Into Subarrays With Minimum Cost I](https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/)
**Difficulty:** `Easy` | **Tags:** `array`, `sorting`, `enumeration`

---

## Problem Description
You are given an array of integers `nums` of length `n`.

The **cost** of an array is the value of its **first** element. For example, the cost of `[1,2,3]` is `1` while the cost of `[3,4,1]` is `3`.

You need to divide `nums` into `3` **disjoint contiguous** subarrays.

Return *the **minimum** possible **sum** of the cost of these subarrays*.

**Example 1:**

```
Input: nums = [1,2,3,12]
Output: 6
Explanation: The best possible way to form 3 subarrays is: [1], [2], and [3,12] at a total cost of 1 + 2 + 3 = 6.
The other possible ways to form 3 subarrays are:
- [1], [2,3], and [12] at a total cost of 1 + 2 + 12 = 15.
- [1,2], [3], and [12] at a total cost of 1 + 3 + 12 = 16.
```

**Example 2:**

```
Input: nums = [5,4,3]
Output: 12
Explanation: The best possible way to form 3 subarrays is: [5], [4], and [3] at a total cost of 5 + 4 + 3 = 12.
It can be shown that 12 is the minimum cost achievable.
```

**Example 3:**

```
Input: nums = [10,3,1,1]
Output: 12
Explanation: The best possible way to form 3 subarrays is: [10,3], [1], and [1] at a total cost of 10 + 1 + 1 = 12.
It can be shown that 12 is the minimum cost achievable.
```

**Constraints:**

* `3 <= n <= 50`
* `1 <= nums[i] <= 50`

---

## Solution & Editorial
# Intuition
Since we must divide the array into exactly 3 contiguous subarrays, the first subarray must always start at index 0. Therefore, the cost of the first subarray is fixed as `nums[0]`. To minimize the total cost, we need to select two additional elements from the remaining array (indices 1 to n-1) to serve as the starting elements of the second and third subarrays. To minimize the sum, we simply pick the two smallest values available in the range `[1, n-1]`.

# Approach
1. The total cost is `nums[0] + min1 + min2`, where `min1` and `min2` are the two smallest elements in `nums[1...n-1]`.
2. Initialize `min1` and `min2` to `INT_MAX`.
3. Iterate through the array starting from index 1. For each element `nums[i]`:
   - If `nums[i]` is smaller than `min1`, update `min2` to the previous `min1` and set `min1` to `nums[i]`.
   - Else if `nums[i]` is smaller than `min2`, update `min2` to `nums[i]`.
4. Return the sum of `nums[0]`, `min1`, and `min2`.

### Visual Trace (Example 1: nums = [1, 2, 3, 12])
| Iteration | nums[i] | min1 | min2 | Action |
|-----------|---------|------|------|--------|
| Start     | -       | INF  | INF  | Init   |
| i=1       | 2       | 2    | INF  | min1=2 |
| i=2       | 3       | 2    | 3    | min2=3 |
| i=3       | 12      | 2    | 3    | No change |

Result: 1 + 2 + 3 = 6.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform a single linear scan of the input array.
- Space complexity: $$O(1)$$, as we only use two integer variables to track the minimums regardless of input size.

# Code
```cpp
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            } else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }
        return nums[0] + min1 + min2;
    }
};
```
