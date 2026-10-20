# [3745. Maximize Expression of Three Elements](https://leetcode.com/problems/maximize-expression-of-three-elements/)
**Difficulty:** `Easy` | **Tags:** `array`, `greedy`, `sorting`, `enumeration`

---

## Problem Description
You are given an integer array `nums`.

Choose three elements `a`, `b`, and `c` from `nums` at **distinct** indices such that the value of the expression `a + b - c` is maximized.

Return an integer denoting the **maximum possible value** of this expression.

**Example 1:**

**Input:** nums = [1,4,2,5]

**Output:** 8

**Explanation:**

We can choose `a = 4`, `b = 5`, and `c = 1`. The expression value is `4 + 5 - 1 = 8`, which is the maximum possible.

**Example 2:**

**Input:** nums = [-2,0,5,-2,4]

**Output:** 11

**Explanation:**

We can choose `a = 5`, `b = 4`, and `c = -2`. The expression value is `5 + 4 - (-2) = 11`, which is the maximum possible.

**Constraints:**

* `3 <= nums.length <= 100`
* `-100 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
To maximize the expression `a + b - c`, we need to maximize the sum of `a` and `b` while minimizing `c`. Since `a`, `b`, and `c` must be chosen from distinct indices, we simply need to pick the two largest available values for `a` and `b`, and the smallest available value for `c`.

# Approach
1. Sort the input array `nums` in descending order.
2. The two largest elements will be at indices `0` and `1`.
3. The smallest element will be at the last index, `nums.size() - 1`.
4. Calculate the result as `nums[0] + nums[1] - nums[nums.size() - 1]`.

### Visual Trace (Example 1: nums = [1, 4, 2, 5])
1. Sort descending: `[5, 4, 2, 1]`
2. `a = 5`, `b = 4`
3. `c = 1`
4. Result: `5 + 4 - 1 = 8`

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting operation, where $$N$$ is the length of the array.
- Space complexity: $$O(1)$$ or $$O(N)$$ depending on the sorting implementation's stack usage, as we perform the operation in-place.

# Code
```cpp
class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        return nums[0]+nums[1]-nums[nums.size()-1];
    }
};
```
