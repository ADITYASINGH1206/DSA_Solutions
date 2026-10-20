# [2704. To Be Or Not To Be](https://leetcode.com/problems/to-be-or-not-to-be/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
Write a function `expect` that helps developers test their code. It should take in any value `val` and return an object with the following two functions.

* `toBe(val)` accepts another value and returns `true` if the two values `===` each other. If they are not equal, it should throw an error `"Not Equal"`.
* `notToBe(val)` accepts another value and returns `true` if the two values `!==` each other. If they are equal, it should throw an error `"Equal"`.

**Example 1:**

```
Input: func = () => expect(5).toBe(5)
Output: {"value": true}
Explanation: 5 === 5 so this expression returns true.
```

**Example 2:**

```
Input: func = () => expect(5).toBe(null)
Output: {"error": "Not Equal"}
Explanation: 5 !== null so this expression throw the error "Not Equal".
```

**Example 3:**

```
Input: func = () => expect(5).notToBe(null)
Output: {"value": true}
Explanation: 5 !== null so this expression returns true.
```

---

## Solution & Editorial
# Intuition
The problem requires creating a factory function that encapsulates a state (`val`) and provides methods to perform strict equality checks. This is a classic application of the closure pattern, where the returned object maintains access to the scope of the `expect` function.

# Approach
1. Define a function `expect` that accepts an initial value `val`.
2. Return an object containing two methods: `toBe` and `notToBe`.
3. Inside `toBe(expected)`, perform a strict equality check (`===`). If the values match, return `true`. Otherwise, throw an error with the message "Not Equal".
4. Inside `notToBe(expected)`, perform a strict inequality check (`!==`). If the values differ, return `true`. Otherwise, throw an error with the message "Equal".

### Visual Trace (Example 1: `expect(5).toBe(5)`)
| Step | Action | State | Result |
| :--- | :--- | :--- | :--- |
| 1 | `expect(5)` | `val = 5` | Returns object |
| 2 | `.toBe(5)` | `expected = 5` | `5 === 5` is true |
| 3 | Return | - | `true` |

# Complexity
- Time complexity: $$O(1)$$ — Each operation (comparison and error throwing) is performed in constant time.
- Space complexity: $$O(1)$$ — The memory usage is constant regardless of the input value, as we only store the reference to the initial value.

# Code
```cpp
/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return {
        toBe(expected) {
            if (val !== expected) {
                throw new Error('Not Equal');
            }
            return true;
        },
        notToBe(expected) {
            if (val === expected) {
                throw new Error('Equal');
            }
            return true;
        },
    };
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
```
