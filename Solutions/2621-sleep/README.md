# [2621. Sleep](https://leetcode.com/problems/sleep/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
Given a positive integer `millis`, write an asynchronous function that sleeps for `millis` milliseconds. It can resolve any value.

**Note** that *minor* deviation from `millis` in the actual sleep duration is acceptable.

**Example 1:**

```
Input: millis = 100
Output: 100
Explanation: It should return a promise that resolves after 100ms.
let t = Date.now();
sleep(100).then(() => {
  console.log(Date.now() - t); // 100
});
```

**Example 2:**

```
Input: millis = 200
Output: 200
Explanation: It should return a promise that resolves after 200ms.
```

**Constraints:**

* `1 <= millis <= 1000`

---

## Solution & Editorial
# Intuition
To implement an asynchronous sleep function, we need to leverage the event loop's non-blocking nature. By wrapping `setTimeout` in a `Promise`, we can pause execution flow without blocking the main thread, allowing the runtime to resolve the promise after the specified duration.

# Approach
1. Define an `async` function `sleep` that accepts an integer `millis`.
2. Return a new `Promise` object.
3. Inside the promise constructor, use the global `setTimeout` function.
4. Pass the `resolve` callback to `setTimeout` to trigger the promise resolution once the timer expires.

### Visual Trace (Example 1: millis = 100)
| Step | Action | State |
| :--- | :--- | :--- |
| 1 | Call `sleep(100)` | `millis` = 100 |
| 2 | Create `new Promise` | Pending |
| 3 | Invoke `setTimeout(resolve, 100)` | Timer started |
| 4 | After 100ms | `resolve()` called |
| 5 | Promise resolves | Fulfilled |

# Complexity
- Time complexity: $$O(1)$$. The setup of the timer is a constant time operation regardless of the value of `millis`.
- Space complexity: $$O(1)$$. We only allocate a single promise object and a timer reference.

# Code
```cpp
/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    return new Promise(r => setTimeout(r, millis));
}

/**
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */
```
