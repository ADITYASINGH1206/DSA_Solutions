# [3876. Construct Uniform Parity Array II](https://leetcode.com/problems/construct-uniform-parity-array-ii/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`

---

## Problem Description
You are given an array `nums1` of `n` **distinct** integers.

You want to construct another array `nums2` of length `n` such that the elements in `nums2` are either **all odd or all even**.

For each index `i`, you must choose **exactly one** of the following (in any order):

* `nums2[i] = nums1[i]`​​​​​​​
* `nums2[i] = nums1[i] - nums1[j]`, for an index `j != i`, such that `nums1[i] - nums1[j] >= 1`

Return `true` if it is possible to construct such an array, otherwise return `false`.

**Example 1:**

**Input:** nums1 = [1,4,7]

**Output:** true

**Explanation:**​​​​​​​​​​​​​​

* Set `nums2[0] = nums1[0] = 1`.
* Set `nums2[1] = nums1[1] - nums1[0] = 4 - 1 = 3`.
* Set `nums2[2] = nums1[2] = 7`.
* `nums2 = [1, 3, 7]`, and all elements are odd. Thus, the answer is `true`.

**Example 2:**

**Input:** nums1 = [2,3]

**Output:** false

**Explanation:**

It is not possible to construct `nums2` such that all elements have the same parity. Thus, the answer is `false`.

**Example 3:**

**Input:** nums1 = [4,6]

**Output:** true

**Explanation:**

* Set `nums2[0] = nums1[0] = 4`.
* Set `nums2[1] = nums1[1] = 6`.
* `nums2 = [4, 6]`, and all elements are even. Thus, the answer is `true`.

**Constraints:**

* `1 <= n == nums1.length <= 105`
* `1 <= nums1[i] <= 109`
* `nums1` consists of distinct integers.

---

## Solution & Editorial
# Intuition
To construct an array `nums2` where all elements share the same parity, we must evaluate if we can force every element to be either even or odd. Since we can transform `nums1[i]` into `nums1[i] - nums1[j]`, we can effectively change the parity of an element if we subtract a value with a different parity. The core constraint is that we need at least one small element of a specific parity to "flip" the parity of larger elements.

# Approach
1. Identify the minimum odd element (`minOdd`) and the minimum even element (`minEven`) in `nums1`.
2. If there are no odd elements, the array is already all even, so return `true`.
3. If there are odd elements, we can make everything odd if we have an odd number smaller than the smallest even number. If `minOdd < minEven`, we can subtract `minOdd` from any even number to make it odd, while keeping odd numbers as they are (or subtracting an even number if available). If `minOdd > minEven`, we cannot force all elements to be odd, and since we cannot easily force all elements to be even without a small odd number to subtract, the condition fails.

### Visual Trace (Example 1: [1, 4, 7])
| Step | Variable | Value |
| :--- | :--- | :--- |
| Init | minOdd | INT_MAX |
| Init | minEven | INT_MAX |
| Process 1 | minOdd | 1 |
| Process 4 | minEven | 4 |
| Process 7 | minOdd | 1 |
| Result | minOdd < minEven | 1 < 4 (True) |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of `nums1`. We perform a single pass to find the minimums.
- Space complexity: $$O(1)$$, as we only store two integer variables.

# Code
```cpp
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;

        for (int x : nums1) {
            if (x % 2 == 0) {
                minEven = min(minEven, x);
            } else {
                minOdd = min(minOdd, x);
            }
        }

        if (minOdd == INT_MAX) {
            return true;
        }

        return minOdd < minEven;
    }
};
```
