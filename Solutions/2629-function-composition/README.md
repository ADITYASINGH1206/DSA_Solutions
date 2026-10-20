# [2629. Function Composition](https://leetcode.com/problems/function-composition/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
Given an array of functions `[f1, f2, f3, ..., fn]`, return a new function `fn` that is the **function composition** of the array of functions.

The **function composition** of `[f(x), g(x), h(x)]` is `fn(x) = f(g(h(x)))`.

The **function composition** of an empty list of functions is the **identity function** `f(x) = x`.

You may assume each function in the array accepts one integer as input and returns one integer as output.

**Example 1:**

```
Input: functions = [x => x + 1, x => x * x, x => 2 * x], x = 4
Output: 65
Explanation:
Evaluating from right to left ...
Starting with x = 4.
2 * (4) = 8
(8) * (8) = 64
(64) + 1 = 65
```

**Example 2:**

```
Input: functions = [x => 10 * x, x => 10 * x, x => 10 * x], x = 1
Output: 1000
Explanation:
Evaluating from right to left ...
10 * (1) = 10
10 * (10) = 100
10 * (100) = 1000
```

**Example 3:**

```
Input: functions = [], x = 42
Output: 42
Explanation:
The composition of zero functions is the identity function
```

**Constraints:**

* `-1000 <= x <= 1000`
* `0 <= functions.length <= 1000`
* all functions accept and return a single integer

---

## Solution & Editorial
# Intuition
Function composition $f(g(h(x)))$ requires evaluating the functions from right to left. By iterating through the array of functions in reverse order, we can maintain a running state that is updated by each function sequentially.

# Approach
1. Define a function that accepts an integer `x`.
2. Initialize a variable `result` with the input value `x`.
3. Iterate through the `functions` vector starting from the last index (`functions.size() - 1`) down to `0`.
4. In each iteration, update `result` by applying the current function `functions[i]` to the current `result`.
5. Return the final `result` after the loop completes.

### Visual Trace (Example 1: functions = [f1, f2, f3], x = 4)
| Iteration | Function | Input (result) | Output (result) |
| :--- | :--- | :--- | :--- |
| Initial | - | - | 4 |
| i = 2 | f3 (2*x) | 4 | 8 |
| i = 1 | f2 (x*x) | 8 | 64 |
| i = 0 | f1 (x+1) | 64 | 65 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of functions in the array, as we perform exactly one function call per element.
- Space complexity: $$O(1)$$, as we only use a single variable to store the intermediate result regardless of the input size.

# Code
```cpp
/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    
    return function(x) {
        let result = x;
        for (let i = functions.length - 1; i >= 0; i--) {
            result = functions[i](result);
        }

        return result;
    }
};
```
