# [2677. Chunk Array](https://leetcode.com/problems/chunk-array/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
Given an array `arr` and a chunk size `size`, return a **chunked** array.

A **chunked** array contains the original elements in `arr`, but consists of subarrays each of length `size`. The length of the last subarray may be less than `size` if `arr.length` is not evenly divisible by `size`.

Please solve it without using lodash's `_.chunk` function.

**Example 1:**

```
Input: arr = [1,2,3,4,5], size = 1
Output: [[1],[2],[3],[4],[5]]
Explanation: The arr has been split into subarrays each with 1 element.
```

**Example 2:**

```
Input: arr = [1,9,6,3,2], size = 3
Output: [[1,9,6],[3,2]]
Explanation: The arr has been split into subarrays with 3 elements. However, only two elements are left for the 2nd subarray.
```

**Example 3:**

```
Input: arr = [8,5,3,2,6], size = 6
Output: [[8,5,3,2,6]]
Explanation: Size is greater than arr.length thus all elements are in the first subarray.
```

**Example 4:**

```
Input: arr = [], size = 1
Output: []
Explanation: There are no elements to be chunked so an empty array is returned.
```

**Constraints:**

* `arr` is a string representing the array.
* `2 <= arr.length <= 105`
* `1 <= size <= arr.length + 1`

---

## Solution & Editorial
# Intuition
The problem requires partitioning a linear sequence into fixed-size segments. Since we need to preserve the relative order of elements and handle the final segment potentially being smaller than the chunk size, a simple linear pass with a sliding window approach is optimal.

# Approach
1. Initialize an empty vector of vectors `ans` to store the resulting chunks.
2. Iterate through the input array `arr` using a loop index `i` that increments by `size` in each iteration.
3. In each step, extract a sub-segment starting at `i` with a length of `size`. If the remaining elements are fewer than `size`, the slice naturally terminates at the end of the array.
4. Push this sub-segment into `ans`.

### Visual Trace (Example 2: arr = [1, 9, 6, 3, 2], size = 3)
| Iteration | i | Slice Range | Subarray | ans (Result) |
|-----------|---|-------------|----------|--------------|
| 1         | 0 | [0, 3)      | [1, 9, 6]| [[1, 9, 6]]  |
| 2         | 3 | [3, 6)      | [3, 2]   | [[1, 9, 6], [3, 2]] |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We visit each element exactly once to construct the chunks.
- Space complexity: $$O(N)$$, as we store all elements of the original array within the new nested structure.

# Code
```cpp
/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function (arr, size) {
    const ans = [];
    for (let i = 0, n = arr.length; i < n; i += size) {
        ans.push(arr.slice(i, i + size));
    }
    return ans;
};
```
