# [2634. Filter Elements from Array](https://leetcode.com/problems/filter-elements-from-array/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
Given an integer array `arr` and a filtering function `fn`, return a filtered array `filteredArr`.

The `fn` function takes one or two arguments:

* `arr[i]` - number from the `arr`
* `i` - index of `arr[i]`

`filteredArr` should only contain the elements from the `arr` for which the expression `fn(arr[i], i)` evaluates to a **truthy** value. A **truthy** value is a value where `Boolean(value)` returns `true`.

Please solve it without the built-in `Array.filter` method.

**Example 1:**

```
Input: arr = [0,10,20,30], fn = function greaterThan10(n) { return n > 10; }
Output: [20,30]
Explanation:
const newArray = filter(arr, fn); // [20, 30]
The function filters out values that are not greater than 10
```

**Example 2:**

```
Input: arr = [1,2,3], fn = function firstIndex(n, i) { return i === 0; }
Output: [1]
Explanation:
fn can also accept the index of each element
In this case, the function removes elements not at index 0
```

**Example 3:**

```
Input: arr = [-2,-1,0,1,2], fn = function plusOne(n) { return n + 1 }
Output: [-2,0,1,2]
Explanation:
Falsey values such as 0 should be filtered out
```

**Constraints:**

* `0 <= arr.length <= 1000`
* `-109 <= arr[i] <= 109`

---

## Solution & Editorial
# Intuition
To filter an array based on a custom predicate function, we must iterate through each element while maintaining its index. By evaluating the predicate for every element, we can conditionally collect only those that satisfy the truthy criteria into a new result container.

# Approach
1. Initialize an empty vector `ans` to store the filtered elements.
2. Iterate through the input array `arr` using a standard loop from `i = 0` to `arr.size() - 1`.
3. For each element `arr[i]`, invoke the provided function `fn(arr[i], i)`.
4. If the result of the function is truthy, append `arr[i]` to the `ans` vector.
5. Return the `ans` vector after the loop completes.

### Visual Trace (Example 1: arr = [0, 10, 20, 30], fn = n > 10)
| Index (i) | Value (arr[i]) | fn(arr[i], i) | Action | ans |
| :--- | :--- | :--- | :--- | :--- |
| 0 | 0 | false | Skip | [] |
| 1 | 10 | false | Skip | [] |
| 2 | 20 | true | Push 20 | [20] |
| 3 | 30 | true | Push 30 | [20, 30] |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array, as we perform a single pass over the input.
- Space complexity: $$O(N)$$ in the worst case where all elements satisfy the condition and are copied into the new vector.

# Code
```cpp
/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let ans =[];
    for (let i = 0; i < arr.length; ++i) {
        if (fn(arr[i], i)) {
            ans.push(arr[i]);
        }
    }
    return ans;
};
```
