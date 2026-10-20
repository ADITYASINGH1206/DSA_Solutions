# [2665. Counter II](https://leetcode.com/problems/counter-ii/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
Write a function `createCounter`. It should accept an initial integer `init`. It should return an object with three functions.

The three functions are:

* `increment()` increases the current value by 1 and then returns it.
* `decrement()` reduces the current value by 1 and then returns it.
* `reset()` sets the current value to `init` and then returns it.

**Example 1:**

```
Input: init = 5, calls = ["increment","reset","decrement"]
Output: [6,5,4]
Explanation:
const counter = createCounter(5);
counter.increment(); // 6
counter.reset(); // 5
counter.decrement(); // 4
```

**Example 2:**

```
Input: init = 0, calls = ["increment","increment","decrement","reset","reset"]
Output: [1,2,1,0,0]
Explanation:
const counter = createCounter(0);
counter.increment(); // 1
counter.increment(); // 2
counter.decrement(); // 1
counter.reset(); // 0
counter.reset(); // 0
```

**Constraints:**

* `-1000 <= init <= 1000`
* `0 <= calls.length <= 1000`
* `calls[i]` is one of "increment", "decrement" and "reset"

---

## Solution & Editorial
# Intuition
The problem requires maintaining a persistent state across multiple function calls. By utilizing a closure or a class-based structure, we can encapsulate the `init` value and the current counter value, ensuring that each operation modifies the state correctly while remaining isolated from other instances.

# Approach
1. Define a class `Counter` that stores two integer members: `init_val` (to preserve the original starting point) and `current_val` (to track the state).
2. Implement `increment()` to perform a pre-increment on `current_val` and return the result.
3. Implement `decrement()` to perform a pre-decrement on `current_val` and return the result.
4. Implement `reset()` to assign `init_val` back to `current_val` and return the result.

### Visual Trace (Example 1: init = 5)
| Operation | current_val (Before) | Action | current_val (After) | Return |
| :--- | :--- | :--- | :--- | :--- |
| increment | 5 | ++ | 6 | 6 |
| reset | 6 | = 5 | 5 | 5 |
| decrement | 5 | -- | 4 | 4 |

# Complexity
- Time complexity: $$O(1)$$ per operation. Each function performs a single arithmetic or assignment operation.
- Space complexity: $$O(1)$$. We only store two integers regardless of the number of calls.

# Code
```cpp
/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let i = init;
    return{
        increment(){
            return ++i;
        },
        decrement(){
            return --i;
        },
        reset(){
            return i=init;
        }
    }


};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
```
