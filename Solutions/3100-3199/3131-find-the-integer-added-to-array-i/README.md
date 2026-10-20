# [3131. Find the Integer Added to Array I](https://leetcode.com/problems/find-the-integer-added-to-array-i/)
**Difficulty:** `Easy` | **Tags:** `array`

---

## Problem Description
You are given two arrays of equal length, `nums1` and `nums2`.

Each element in `nums1` has been increased (or decreased in the case of negative) by an integer, represented by the variable `x`.

As a result, `nums1` becomes **equal** to `nums2`. Two arrays are considered **equal** when they contain the same integers with the same frequencies.

Return the integer `x`.

**Example 1:**

**Input:** nums1 = [2,6,4], nums2 = [9,7,5]

**Output:** 3

**Explanation:**

The integer added to each element of `nums1` is 3.

**Example 2:**

**Input:** nums1 = [10], nums2 = [5]

**Output:** -5

**Explanation:**

The integer added to each element of `nums1` is -5.

**Example 3:**

**Input:** nums1 = [1,1,1,1], nums2 = [1,1,1,1]

**Output:** 0

**Explanation:**

The integer added to each element of `nums1` is 0.

**Constraints:**

* `1 <= nums1.length == nums2.length <= 100`
* `0 <= nums1[i], nums2[i] <= 1000`
* The test cases are generated in a way that there is an integer `x` such that `nums1` can become equal to `nums2` by adding `x` to each element of `nums1`.

---

## Solution & Editorial
# Intuition
Since every element in `nums1` is increased by the same constant `x` to transform it into `nums2`, the relative order and the distribution of values remain preserved. Specifically, the minimum value in `nums1` must map to the minimum value in `nums2` after the addition of `x`.

# Approach
1. Find the minimum element of `nums1` using `std::min_element`.
2. Find the minimum element of `nums2` using `std::min_element`.
3. The difference between these two minimums, `min2 - min1`, is the constant integer `x` added to every element.

### Visual Trace (Example 1)
`nums1 = [2, 6, 4]`, `nums2 = [9, 7, 5]`

| Step | Operation | Result |
| :--- | :--- | :--- |
| 1 | `min_element(nums1)` | 2 |
| 2 | `min_element(nums2)` | 5 |
| 3 | `5 - 2` | 3 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the arrays. We perform two linear scans to find the minimums.
- Space complexity: $$O(1)$$, as we only store two integer variables.

# Code
```cpp
class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int min1 = *min_element(nums1.begin(),nums1.end());
        int min2 = *min_element(nums2.begin(),nums2.end());
        return (min2-min1);
    }
};
```
