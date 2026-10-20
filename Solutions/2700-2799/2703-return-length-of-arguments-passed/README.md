# [2703. Return Length of Arguments Passed](https://leetcode.com/problems/return-length-of-arguments-passed/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
Write a function `argumentsLength` that returns the count of arguments passed to it.

**Example 1:**

```
Input: args = [5]
Output: 1
Explanation:
argumentsLength(5); // 1

One value was passed to the function so it should return 1.
```

**Example 2:**

```
Input: args = [{}, null, "3"]
Output: 3
Explanation: 
argumentsLength({}, null, "3"); // 3

Three values were passed to the function so it should return 3.
```

**Constraints:**

* `args` is a valid JSON array
* `0 <= args.length <= 100`

---

## Solution & Editorial
# Intuition
The problem asks to determine the number of arguments passed to a function. In modern C++, this is elegantly handled using variadic templates and parameter packs.

# Approach
1. Define a function template `argumentsLength` that accepts a parameter pack `Args...`.
2. Use the `sizeof...` operator, which is a compile-time feature in C++ that returns the number of elements in a parameter pack.
3. Since the operation is performed at compile-time, the function effectively returns the count of arguments with zero runtime overhead.

### Visual Trace
Example: `argumentsLength(1, 2, 3)`
- `Args` pack: `{int, int, int}`
- `sizeof...(Args)`: 3
- Return: 3

# Complexity
- Time complexity: $$O(1)$$. The `sizeof...` operator is evaluated at compile-time.
- Space complexity: $$O(1)$$. No auxiliary memory is allocated.

# Code
```cpp
/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    return args.length
};

/**
 * argumentsLength(1, 2, 3); // 3
 */
```
