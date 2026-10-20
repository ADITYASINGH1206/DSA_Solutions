# [3727. Maximum Alternating Sum of Squares](https://leetcode.com/problems/maximum-alternating-sum-of-squares/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `sorting`

---

## Problem Description
You are given an integer array `nums`. You may **rearrange the elements** in any order.

The **alternating score** of an array `arr` is defined as:

* `score = arr[0]2 - arr[1]2 + arr[2]2 - arr[3]2 + ...`

Return an integer denoting the **maximum possible alternating score** of `nums` after rearranging its elements.

**Example 1:**

**Input:** nums = [1,2,3]

**Output:** 12

**Explanation:**

A possible rearrangement for `nums` is `[2,1,3]`, which gives the maximum alternating score among all possible rearrangements.

The alternating score is calculated as:

`score = 22 - 12 + 32 = 4 - 1 + 9 = 12`

**Example 2:**

**Input:** nums = [1,-1,2,-2,3,-3]

**Output:** 16

**Explanation:**

A possible rearrangement for `nums` is `[-3,-1,-2,1,3,2]`, which gives the maximum alternating score among all possible rearrangements.

The alternating score is calculated as:

`score = (-3)2 - (-1)2 + (-2)2 - (1)2 + (3)2 - (2)2 = 9 - 1 + 4 - 1 + 9 - 4 = 16`

**Constraints:**

* `1 <= nums.length <= 105`
* `-4 * 104 <= nums[i] <= 4 * 104`

---

## Solution & Editorial
# Intuition
The alternating score formula is $arr[0]^2 - arr[1]^2 + arr[2]^2 - arr[3]^2 + \dots$. Since we can rearrange the elements, we want to maximize the sum of squares at even indices and minimize the sum of squares at odd indices. By transforming each element into its square, the problem reduces to partitioning the set of squared values into two groups: one of size $\lceil N/2 \rceil$ (to be added) and one of size $\lfloor N/2 \rfloor$ (to be subtracted).

# Approach
1. Transform every element $x$ in `nums` into its square $x^2$ and store these in a vector `sq`.
2. Let $h = N/2$. We need to select the $h$ smallest squared values to be subtracted. 
3. Use `std::nth_element` to partition the `sq` vector such that the $h$ smallest elements are moved to the front of the vector.
4. Calculate the `total` sum of all squared values and the `small` sum of the first $h$ elements.
5. The maximum alternating score is given by $(total - small) - small = total - 2 \times small$.

### Visual Trace (Example 1: [1, 2, 3])
- `sq` = [1, 4, 9]
- `h` = 3 / 2 = 1
- `nth_element` partitions `sq` so the smallest 1 element is at index 0: `sq` = [1, 4, 9] (or similar)
- `total` = 1 + 4 + 9 = 14
- `small` = 1
- Result = 14 - 2(1) = 12

# Complexity
- Time complexity: $$O(N)$$ on average, due to the `nth_element` algorithm which performs linear-time selection.
- Space complexity: $$O(N)$$ to store the squared values of the input array.

# Code
```cpp
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> sq;
        for (int x : nums) sq.push_back(1LL * x * x);
        int h = sq.size() / 2;
        nth_element(sq.begin(), sq.begin() + h, sq.end()); 
        long long total = accumulate(sq.begin(), sq.end(), 0LL);
        long long small = accumulate(sq.begin(), sq.begin() + h, 0LL);
        return total - 2 * small;  
    }
};
```
