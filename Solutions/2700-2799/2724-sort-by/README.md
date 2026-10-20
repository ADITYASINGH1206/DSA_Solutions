# [2724. Sort By](https://leetcode.com/problems/sort-by/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
Given an array `arr` and a function `fn`, return a sorted array `sortedArr`. You can assume `fn` only returns numbers and those numbers determine the sort order of `sortedArr`. `sortedArr` must be sorted in **ascending order** by `fn` output.

You may assume that `fn` will never duplicate numbers for a given array.

**Example 1:**

```
Input: arr = [5, 4, 1, 2, 3], fn = (x) => x
Output: [1, 2, 3, 4, 5]
Explanation: fn simply returns the number passed to it so the array is sorted in ascending order.
```

**Example 2:**

```
Input: arr = [{"x": 1}, {"x": 0}, {"x": -1}], fn = (d) => d.x
Output: [{"x": -1}, {"x": 0}, {"x": 1}]
Explanation: fn returns the value for the "x" key. So the array is sorted based on that value.
```

**Example 3:**

```
Input: arr = [[3, 4], [5, 2], [10, 1]], fn = (x) => x[1]
Output: [[10, 1], [5, 2], [3, 4]]
Explanation: arr is sorted in ascending order by number at index=1. 
```

**Constraints:**

* `arr` is a valid JSON array
* `fn` is a function that returns a number
* `1 <= arr.length <= 5 * 105`

---

## Solution & Editorial
# Intuition
The problem requires sorting an array based on the output of a transformation function `fn`. Since we need to order elements based on a computed scalar value, the standard library's `std::sort` with a custom comparator is the most efficient and idiomatic approach.

# Approach
1. Utilize `std::sort` on the input vector `arr`.
2. Provide a lambda function as the third argument to `std::sort`. This lambda captures `fn` and compares two elements `a` and `b` by evaluating `fn(a) < fn(b)`.
3. The sorting algorithm performs $O(N \log N)$ comparisons, where each comparison involves a call to `fn`.

### Visual Trace (Example 1: arr = [5, 4, 1, 2, 3], fn = x => x)
| Step | Array State | Comparison | Result |
| :--- | :--- | :--- | :--- |
| Initial | [5, 4, 1, 2, 3] | - | - |
| Iteration 1 | [4, 5, 1, 2, 3] | 5 > 4 | Swap |
| Iteration 2 | [1, 4, 5, 2, 3] | 4 > 1 | Swap |
| ... | ... | ... | ... |
| Final | [1, 2, 3, 4, 5] | - | Sorted |

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N$$ is the length of the array. The `std::sort` algorithm uses Introsort, which guarantees logarithmic depth relative to the number of elements.
- Space complexity: $$O(\log N)$$ due to the recursion stack used by `std::sort` (or $$O(N)$$ depending on implementation specifics regarding temporary storage).

# Code
```cpp
type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Fn = (value: JSONValue) => number

function sortBy(arr: any[], fn: Function): any[] {
    return arr.sort((a, b) => fn(a) - fn(b));
}
```
