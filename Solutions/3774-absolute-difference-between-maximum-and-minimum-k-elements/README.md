# [3774. Absolute Difference Between Maximum and Minimum K Elements](https://leetcode.com/problems/absolute-difference-between-maximum-and-minimum-k-elements/)
**Difficulty:** `Easy` | **Tags:** `array`, `sorting`

---

## Problem Description
You are given an integer array `nums` and an integer `k`.

Find the absolute difference between:

* the **sum** of the `k` **largest** elements in the array; and
* the **sum** of the `k` **smallest** elements in the array.

Return an integer denoting this difference.

**Example 1:**

**Input:** nums = [5,2,2,4], k = 2

**Output:** 5

**Explanation:**

* The `k = 2` largest elements are 4 and 5. Their sum is `4 + 5 = 9`.
* The `k = 2` smallest elements are 2 and 2. Their sum is `2 + 2 = 4`.
* The absolute difference is `abs(9 - 4) = 5`.

**Example 2:**

**Input:** nums = [100], k = 1

**Output:** 0

**Explanation:**

* The largest element is 100.
* The smallest element is 100.
* The absolute difference is `abs(100 - 100) = 0`.

**Constraints:**

* `1 <= n == nums.length <= 100`
* `1 <= nums[i] <= 100`
* `1 <= k <= n`

---

## Solution & Editorial
# Intuition
To find the sum of the $k$ smallest and $k$ largest elements, the most straightforward approach is to order the array. Once sorted, the $k$ smallest elements occupy the beginning of the array, and the $k$ largest elements occupy the end.

# Approach
1. Sort the input vector `nums` in non-decreasing order using `std::sort`.
2. Initialize two integer accumulators, `mini` and `maxi`, to zero.
3. Iterate from index `0` to `k-1` to calculate the sum of the $k$ smallest elements and store it in `mini`.
4. Iterate from index `n-1` down to `n-k` to calculate the sum of the $k$ largest elements and store it in `maxi`.
5. Return the absolute difference `abs(maxi - mini)`.

### Visual Trace (Example 1: nums = [5, 2, 2, 4], k = 2)
- **Initial**: `nums = [5, 2, 2, 4]`, `k = 2`
- **Sorted**: `nums = [2, 2, 4, 5]`
- **Smallest Sum (mini)**: `nums[0] + nums[1] = 2 + 2 = 4`
- **Largest Sum (maxi)**: `nums[3] + nums[2] = 5 + 4 = 9`
- **Result**: `abs(9 - 4) = 5`

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting operation, where $N$ is the number of elements in the array. The subsequent linear scans take $$O(k)$$, which is bounded by $$O(N)$$.
- Space complexity: $$O(1)$$ (or $$O(\log N)$$ depending on the implementation of `std::sort`), as we only use a few integer variables for accumulation.

# Code
```cpp
class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxi = 0;
        int mini = 0;
        int n = nums.size();
        for(int i = 0;i<k && i<n;i++){
            mini += nums[i];
        }

        for(int i = n-1;i>n-k-1 && i>=0;i--){
            maxi += nums[i];
        }

        return abs(maxi-mini);
    }
};
```
