# [2721. Execute Asynchronous Functions in Parallel](https://leetcode.com/problems/execute-asynchronous-functions-in-parallel/)
**Difficulty:** `Medium` | **Tags:** `Algorithm`

---

## Problem Description
Given an array of asynchronous functions `functions`, return a new promise `promise`. Each function in the array accepts no arguments and returns a promise. All the promises should be executed in parallel.

`promise` resolves:

* When all the promises returned from `functions` were resolved successfully in parallel. The resolved value of `promise` should be an array of all the resolved values of promises in the same order as they were in the `functions`. The `promise` should resolve when all the asynchronous functions in the array have completed execution in parallel.

`promise` rejects:

* When any of the promises returned from `functions` were rejected. `promise` should also reject with the reason of the first rejection.

Please solve it without using the built-in `Promise.all` function.

**Example 1:**

```
Input: functions = [
  () => new Promise(resolve => setTimeout(() => resolve(5), 200))
]
Output: {"t": 200, "resolved": [5]}
Explanation: 
promiseAll(functions).then(console.log); // [5]

The single function was resolved at 200ms with a value of 5.
```

**Example 2:**

```
Input: functions = [
    () => new Promise(resolve => setTimeout(() => resolve(1), 200)), 
    () => new Promise((resolve, reject) => setTimeout(() => reject("Error"), 100))
]
Output: {"t": 100, "rejected": "Error"}
Explanation: Since one of the promises rejected, the returned promise also rejected with the same error at the same time.
```

**Example 3:**

```
Input: functions = [
    () => new Promise(resolve => setTimeout(() => resolve(4), 50)), 
    () => new Promise(resolve => setTimeout(() => resolve(10), 150)), 
    () => new Promise(resolve => setTimeout(() => resolve(16), 100))
]
Output: {"t": 150, "resolved": [4, 10, 16]}
Explanation: All the promises resolved with a value. The returned promise resolved when the last promise resolved.
```

**Constraints:**

* `functions` is an array of functions that returns promises
* `1 <= functions.length <= 10`

---

## Solution & Editorial
# Intuition
To implement `Promise.all` behavior, we must execute all asynchronous functions concurrently and track their completion. The core requirement is to maintain the original order of results while ensuring that if any single promise rejects, the entire operation fails immediately.

# Approach
1. Initialize a result array `ans` of the same size as `functions` to store resolved values at their respective indices.
2. Maintain a counter `cnt` to track how many promises have successfully resolved.
3. Iterate through the `functions` array. For each function at index `i`, invoke it and attach a `.then()` handler to store the result in `ans[i]` and increment `cnt`.
4. If `cnt` reaches the total number of functions, resolve the main promise with `ans`.
5. Attach a `.catch()` handler to each function to immediately reject the main promise if any individual promise fails.

### Visual Trace (Example 3)
| Step | Action | `ans` | `cnt` | Status |
| :--- | :--- | :--- | :--- | :--- |
| 0 | Init | `[null, null, null]` | 0 | Pending |
| 1 | f[0] resolves (50ms) | `[4, null, null]` | 1 | Pending |
| 2 | f[2] resolves (100ms) | `[4, null, 16]` | 2 | Pending |
| 3 | f[1] resolves (150ms) | `[4, 10, 16]` | 3 | Resolved |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of functions. Each function is invoked once, and each promise resolution/rejection is handled in constant time.
- Space complexity: $$O(N)$$, required to store the results array and the internal promise state.

# Code
```cpp
async function promiseAll<T>(functions: (() => Promise<T>)[]): Promise<T[]> {
    return new Promise<T[]>((resolve, reject) => {
        let cnt = 0;
        const ans = new Array(functions.length);
        for (let i = 0; i < functions.length; ++i) {
            const f = functions[i];
            f()
                .then(res => {
                    ans[i] = res;
                    cnt++;
                    if (cnt === functions.length) {
                        resolve(ans);
                    }
                })
                .catch(err => {
                    reject(err);
                });
        }
    });
}

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */
```
