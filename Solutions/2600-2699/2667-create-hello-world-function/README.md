# [2667. Create Hello World Function](https://leetcode.com/problems/create-hello-world-function/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
Write a function `createHelloWorld`. It should return a new function that always returns `"Hello World"`.

**Example 1:**

```
Input: args = []
Output: "Hello World"
Explanation:
const f = createHelloWorld();
f(); // "Hello World"

The function returned by createHelloWorld should always return "Hello World".
```

**Example 2:**

```
Input: args = [{},null,42]
Output: "Hello World"
Explanation:
const f = createHelloWorld();
f({}, null, 42); // "Hello World"

Any arguments could be passed to the function but it should still always return "Hello World".
```

**Constraints:**

* `0 <= args.length <= 10`

---

## Solution & Editorial
# Intuition
The problem asks for a higher-order function that returns a closure. Regardless of the input arguments provided to the inner function, the output must remain constant.

# Approach
1. Define a function `createHelloWorld` that returns a lambda expression or a function object.
2. The returned function accepts a variadic number of arguments (using `...args` in JS or variadic templates in C++).
3. The inner function ignores all input parameters and returns the string literal "Hello World".

### Visual Trace
| Step | Action | Input | Output |
| :--- | :--- | :--- | :--- |
| 1 | Call `createHelloWorld()` | N/A | Function `f` |
| 2 | Call `f()` | `[]` | "Hello World" |
| 3 | Call `f(1, 2, 3)` | `[1, 2, 3]` | "Hello World" |

# Complexity
- Time complexity: $$O(1)$$. The function performs a constant time return operation regardless of the number of arguments.
- Space complexity: $$O(1)$$. No additional memory is allocated proportional to the input size.

# Code
```cpp
/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return function(...args) {
        return "Hello World";
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */
```
