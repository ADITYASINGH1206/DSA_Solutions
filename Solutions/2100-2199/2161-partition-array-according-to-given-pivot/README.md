# [2161. Partition Array According to Given Pivot](https://leetcode.com/problems/partition-array-according-to-given-pivot/)
**Difficulty:** `Medium` | **Tags:** `array`, `two-pointers`, `simulation`

---

## Problem Description
You are given a **0-indexed** integer array `nums` and an integer `pivot`. Rearrange `nums` such that the following conditions are satisfied:

* Every element less than `pivot` appears **before** every element greater than `pivot`.
* Every element equal to `pivot` appears **in between** the elements less than and greater than `pivot`.
* The **relative order** of the elements less than `pivot` and the elements greater than `pivot` is maintained.
  + More formally, consider every `pi`, `pj` where `pi` is the new position of the `ith` element and `pj` is the new position of the `jth` element. If `i < j` and **both** elements are smaller (*or larger*) than `pivot`, then `pi < pj`.

Return `nums` *after the rearrangement.*

**Example 1:**

```
Input: nums = [9,12,5,10,14,3,10], pivot = 10
Output: [9,5,3,10,10,12,14]
Explanation: 
The elements 9, 5, and 3 are less than the pivot so they are on the left side of the array.
The elements 12 and 14 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [9, 5, 3] and [12, 14] are the respective orderings.
```

**Example 2:**

```
Input: nums = [-3,4,3,2], pivot = 2
Output: [-3,2,4,3]
Explanation: 
The element -3 is less than the pivot so it is on the left side of the array.
The elements 4 and 3 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [-3] and [4, 3] are the respective orderings.
```

**Constraints:**

* `1 <= nums.length <= 105`
* `-106 <= nums[i] <= 106`
* `pivot` equals to an element of `nums`.

---

## Solution & Editorial
# Intuition
The problem requires partitioning an array into three distinct segments based on a pivot value while strictly maintaining the relative order of elements within each segment. Since we need to preserve the original sequence for elements smaller than, equal to, and greater than the pivot, a multi-pass approach is the most intuitive and robust way to ensure stability.

# Approach
1. Initialize an empty result vector `ans` of the same size as `nums`.
2. Perform three sequential passes over the input array `nums`:
   - **Pass 1**: Iterate through `nums` and append all elements strictly less than `pivot` to `ans`.
   - **Pass 2**: Iterate through `nums` and append all elements equal to `pivot` to `ans`.
   - **Pass 3**: Iterate through `nums` and append all elements strictly greater than `pivot` to `ans`.
3. Return the constructed `ans` vector.

### Visual Trace (Example 1: nums = [9,12,5,10,14,3,10], pivot = 10)
| Pass | Condition | Elements Added | `ans` State |
| :--- | :--- | :--- | :--- |
| 1 | x < 10 | 9, 5, 3 | [9, 5, 3] |
| 2 | x == 10 | 10, 10 | [9, 5, 3, 10, 10] |
| 3 | x > 10 | 12, 14 | [9, 5, 3, 10, 10, 12, 14] |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the input array. We traverse the array exactly three times, performing constant-time operations in each iteration.
- Space complexity: $$O(N)$$ to store the resulting array of size $$N$$.

# Code
```cpp
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans;
        for (int x : nums) {
            if (x < pivot) {
                ans.push_back(x);
            }
        }
        for (int x : nums) {
            if (x == pivot) {
                ans.push_back(x);
            }
        }
        for (int x : nums) {
            if (x > pivot) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
```
