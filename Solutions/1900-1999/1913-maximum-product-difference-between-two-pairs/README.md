# [1913. Maximum Product Difference Between Two Pairs](https://leetcode.com/problems/maximum-product-difference-between-two-pairs/)
**Difficulty:** `Easy` | **Tags:** `array`, `sorting`, `quicksort`

---

## Problem Description
The **product difference** between two pairs `(a, b)` and `(c, d)` is defined as `(a * b) - (c * d)`.

* For example, the product difference between `(5, 6)` and `(2, 7)` is `(5 * 6) - (2 * 7) = 16`.

Given an integer array `nums`, choose four **distinct** indices `w`, `x`, `y`, and `z` such that the **product difference** between pairs `(nums[w], nums[x])` and `(nums[y], nums[z])` is **maximized**.

Return *the **maximum** such product difference*.

**Example 1:**

```

Input: nums = [5,6,2,7,4]
Output: 34
Explanation: We can choose indices 1 and 3 for the first pair (6, 7) and indices 2 and 4 for the second pair (2, 4).
The product difference is (6 * 7) - (2 * 4) = 34.
```

**Example 2:**

```

Input: nums = [4,2,5,9,7,4,8]
Output: 64
Explanation: We can choose indices 3 and 6 for the first pair (9, 8) and indices 1 and 5 for the second pair (2, 4).
The product difference is (9 * 8) - (2 * 4) = 64.
```

**Constraints:**

* `4 <= nums.length <= 104`
* `1 <= nums[i] <= 104`

---

## Solution & Editorial
# Intuition
To maximize the product difference $(a \times b) - (c \times d)$, we need to maximize the minuend $(a \times b)$ and minimize the subtrahend $(c \times d)$. Since all elements are positive, this is achieved by selecting the two largest numbers for the first pair and the two smallest numbers for the second pair.

# Approach
1. Sort the array `nums` in descending order using `std::sort` with `rbegin()` and `rend()` iterators.
2. After sorting, the two largest elements are at indices `0` and `1`, and the two smallest elements are at indices `n-1` and `n-2`.
3. Calculate the result as `(nums[0] * nums[1]) - (nums[n-1] * nums[n-2])`.

### Visual Trace (Example 1: nums = [5, 6, 2, 7, 4])
1. **Sort descending**: `[7, 6, 5, 4, 2]`
2. **Identify pairs**:
   - Largest: `nums[0]=7`, `nums[1]=6`
   - Smallest: `nums[4]=2`, `nums[3]=4`
3. **Calculation**:
   - `(7 * 6) - (2 * 4) = 42 - 8 = 34`

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting operation, where $$N$$ is the length of the input array.
- Space complexity: $$O(1)$$ (or $$O(\log N)$$ depending on the implementation of `std::sort`), as we perform the operation in-place without auxiliary data structures.

# Code
```cpp
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int n = nums.size();
        return ((nums[0]*nums[1])-(nums[n-1]*nums[n-2]));
    }
};
```
