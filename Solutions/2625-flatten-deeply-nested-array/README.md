# [2625. Flatten Deeply Nested Array](https://leetcode.com/problems/flatten-deeply-nested-array/)
**Difficulty:** `Medium` | **Tags:** `Algorithm`

---

## Problem Description
Given a **multi-dimensional** array `arr` and a depth `n`, return a **flattened** version of that array.

A **multi-dimensional** array is a recursive data structure that contains integers or other **multi-dimensional** arrays.

A **flattened** array is a version of that array with some or all of the sub-arrays removed and replaced with the actual elements in that sub-array. This flattening operation should only be done if the current depth of nesting is less than `n`. The depth of the elements in the first array are considered to be `0`.

Please solve it without the built-in `Array.flat` method.

**Example 1:**

```
Input
arr = [1, 2, 3, [4, 5, 6], [7, 8, [9, 10, 11], 12], [13, 14, 15]]
n = 0
Output
[1, 2, 3, [4, 5, 6], [7, 8, [9, 10, 11], 12], [13, 14, 15]]

Explanation
Passing a depth of n=0 will always result in the original array. This is because the smallest possible depth of a subarray (0) is not less than n=0. Thus, no subarray should be flattened.
```

**Example 2:**

```
Input
arr = [1, 2, 3, [4, 5, 6], [7, 8, [9, 10, 11], 12], [13, 14, 15]]
n = 1
Output
[1, 2, 3, 4, 5, 6, 7, 8, [9, 10, 11], 12, 13, 14, 15]

Explanation
The subarrays starting with 4, 7, and 13 are all flattened. This is because their depth of 0 is less than 1. However [9, 10, 11] remains unflattened because its depth is 1.
```

**Example 3:**

```
Input
arr = [[1, 2, 3], [4, 5, 6], [7, 8, [9, 10, 11], 12], [13, 14, 15]]
n = 2
Output
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]

Explanation
The maximum depth of any subarray is 1. Thus, all of them are flattened.
```

**Constraints:**

* `0 <= count of numbers in arr <= 105`
* `0 <= count of subarrays in arr <= 105`
* `maxDepth <= 1000`
* `-1000 <= each number <= 1000`
* `0 <= n <= 1000`

---

## Solution & Editorial
# Intuition
The problem requires flattening a nested structure up to a specific depth `n`. This is a classic recursive problem where each level of nesting acts as a state transition. If the current depth allows further flattening (i.e., `n > 0`), we decompose sub-arrays; otherwise, we treat them as atomic elements.

# Approach
1. Define a recursive function that accepts the current array and the remaining depth `n`.
2. Base Case: If `n == 0`, return the array as is, as no further flattening is permitted.
3. Recursive Step: Iterate through each element of the input array. If an element is a sub-array and `n > 0`, recursively call the function with `n - 1` and append the results to the current result set.
4. If the element is an integer or `n == 0`, simply append the element to the result.

### Visual Trace (Example 2: n=1)
Input: `[1, [4, 5]]`, `n=1`
- `flat([1, [4, 5]], 1)`
  - Element `1`: Not an array, push `1`.
  - Element `[4, 5]`: Is array, `n=1 > 0`. Call `flat([4, 5], 0)`.
    - `flat([4, 5], 0)` returns `[4, 5]` (Base case `n=0`).
  - Push `4`, `5` to result.
- Result: `[1, 4, 5]`

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the total number of elements across all nesting levels. Each element is visited exactly once during the recursive traversal.
- Space complexity: $$O(D)$$, where $$D$$ is the maximum depth of the array, representing the maximum depth of the recursion stack.

# Code
```cpp
type MultiDimensionalArray = (number | MultiDimensionalArray)[];

var flat = function (arr: MultiDimensionalArray, n: number): MultiDimensionalArray {
    if (!n) {
        return arr;
    }
    const ans: MultiDimensionalArray = [];
    for (const x of arr) {
        if (Array.isArray(x) && n) {
            ans.push(...flat(x, n - 1));
        } else {
            ans.push(x);
        }
    }
    return ans;
};
```
