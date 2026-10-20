# [2620. Counter](https://leetcode.com/problems/counter/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
Given an integer `n`, return a `counter` function. This `counter` function initially returns `n` and then returns 1 more than the previous value every subsequent time it is called (`n`, `n + 1`, `n + 2`, etc).

**Example 1:**

```
Input: 
n = 10 
["call","call","call"]
Output: [10,11,12]
Explanation: 
counter() = 10 // The first time counter() is called, it returns n.
counter() = 11 // Returns 1 more than the previous time.
counter() = 12 // Returns 1 more than the previous time.
```

**Example 2:**

```
Input: 
n = -2
["call","call","call","call","call"]
Output: [-2,-1,0,1,2]
Explanation: counter() initially returns -2. Then increases after each sebsequent call.
```

**Constraints:**

* `-1000 <= n <= 1000`
* `0 <= calls.length <= 1000`
* `calls[i] === "call"`

---

## Solution & Editorial
# Intuition
The problem requires maintaining a persistent state across multiple function calls. In C++, this is elegantly handled using a lambda function with a capture clause that maintains the state of the variable `n`.

# Approach
1. Define a function `createCounter` that accepts an integer `n`.
2. Return a lambda function that captures `n` by reference (`[&n]`).
3. Inside the lambda, return the current value of `n` and then increment it using the post-increment operator `n++`.

### Visual Trace (n = 10)
| Call | State (n) | Return Value | Post-call State (n) |
| :--- | :--- | :--- | :--- |
| 1st | 10 | 10 | 11 |
| 2nd | 11 | 11 | 12 |
| 3rd | 12 | 12 | 13 |

# Complexity
- Time complexity: $$O(1)$$ per call, as incrementing an integer is a constant-time operation.
- Space complexity: $$O(1)$$, as we only store a single integer state.

# Code
```cpp
/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    return function() {
        return n++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
```
