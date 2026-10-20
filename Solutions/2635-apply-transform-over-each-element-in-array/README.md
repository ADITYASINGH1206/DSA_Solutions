# [2635. Apply Transform Over Each Element in Array](https://leetcode.com/problems/apply-transform-over-each-element-in-array/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
Given an integer array `arr` and a mapping function `fn`, return a new array with a transformation applied to each element.

The returned array should be created such that `returnedArray[i] = fn(arr[i], i)`.

Please solve it without the built-in `Array.map` method.

**Example 1:**

```
Input: arr = [1,2,3], fn = function plusone(n) { return n + 1; }
Output: [2,3,4]
Explanation:
const newArray = map(arr, plusone); // [2,3,4]
The function increases each value in the array by one.
```

**Example 2:**

```
Input: arr = [1,2,3], fn = function plusI(n, i) { return n + i; }
Output: [1,3,5]
Explanation: The function increases each value by the index it resides in.
```

**Example 3:**

```
Input: arr = [10,20,30], fn = function constant() { return 42; }
Output: [42,42,42]
Explanation: The function always returns 42.
```

**Constraints:**

* `0 <= arr.length <= 1000`
* `-109 <= arr[i] <= 109`
* `fn` returns an integer.

---

## Solution & Editorial
# Intuition
The problem requires applying a transformation function `fn` to every element in an array, where the transformation depends on both the element's value and its index. Since we need to produce a new array (or modify the existing one in-place), a single linear pass is sufficient.

# Approach
1. Initialize a loop that iterates through the input array `arr` from index `0` to `arr.length - 1`.
2. For each index `i`, invoke the function `fn` passing the current element `arr[i]` and the index `i` as arguments.
3. Update the element at `arr[i]` with the result returned by `fn`.
4. Return the modified array.

### Visual Trace (Example 2: arr = [1, 2, 3], fn = n + i)
| Iteration | i | arr[i] | fn(arr[i], i) | Resulting arr |
|-----------|---|--------|---------------|---------------|
| 1         | 0 | 1      | 1 + 0 = 1     | [1, 2, 3]     |
| 2         | 1 | 2      | 2 + 1 = 3     | [1, 3, 3]     |
| 3         | 2 | 3      | 3 + 2 = 5     | [1, 3, 5]     |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array, as we perform exactly one transformation per element.
- Space complexity: $$O(1)$$, as we are modifying the array in-place without allocating additional data structures.

# Code
```cpp
/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    for (let i = 0; i < arr.length; ++i) {
        arr[i] = fn(arr[i], i);
    }   
    return arr;
};
```
