# [3875. Construct Uniform Parity Array I](https://leetcode.com/problems/construct-uniform-parity-array-i/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`

---

## Problem Description
You are given an array `nums1` of `n` **distinct** integers.

You want to construct another array `nums2` of length `n` such that the elements in `nums2` are either **all odd or all even**.

For each index `i`, you must choose **exactly one** of the following (in any order):

* `nums2[i] = nums1[i]`
* `nums2[i] = nums1[i] - nums1[j]`, for an index `j != i`

Return `true` if it is possible to construct such an array, otherwise, return `false`.

**Example 1:**

**Input:** nums1 = [2,3]

**Output:** true

**Explanation:**

* Choose `nums2[0] = nums1[0] - nums1[1] = 2 - 3 = -1`.
* Choose `nums2[1] = nums1[1] = 3`.
* `nums2 = [-1, 3]`, and both elements are odd. Thus, the answer is `true`​​​​​​​.

**Example 2:**

**Input:** nums1 = [4,6]

**Output:** true

**Explanation:**​​​​​​​

* Choose `nums2[0] = nums1[0] = 4`.
* Choose `nums2[1] = nums1[1] = 6`.
* `nums2 = [4, 6]`, and all elements are even. Thus, the answer is `true`.

**Constraints:**

* `1 <= n == nums1.length <= 100`
* `1 <= nums1[i] <= 100`
* `nums1` consists of distinct integers.

---

## Solution & Editorial
# Intuition
To determine if we can construct an array `nums2` where all elements share the same parity (all odd or all even), we must analyze the parity transformation rules. For any element `nums1[i]`, we can either keep it as `nums1[i]` or transform it into `nums1[i] - nums1[j]`. 

# Approach
1. The parity of `nums1[i] - nums1[j]` is determined by the parity of the difference between two numbers. Specifically, `odd - odd = even`, `even - even = even`, and `odd - even = odd` (or vice versa).
2. Given the constraints and the flexibility to pick any `j != i` for each `i`, we can always manipulate the parity of any element to match the desired target parity (all even or all odd) as long as the array size allows for at least one pair to perform the subtraction.
3. Since the problem constraints guarantee `n >= 1` and the logic holds for all valid inputs, the answer is always `true`.

# Complexity
- Time complexity: $$O(1)$$. The solution returns a constant boolean value regardless of the input size.
- Space complexity: $$O(1)$$. No auxiliary data structures are used.

# Code
```cpp
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};
```
