# [2623. Memoize](https://leetcode.com/problems/memoize/)
**Difficulty:** `Medium` | **Tags:** `Algorithm`

---

## Problem Description
Given a function `fn`, return a **memoized** version of that function.

A **memoized**function is a function that will never be called twice with the same inputs. Instead it will return a cached value.

You can assume there are **3**possible input functions: `sum`**,** `fib`**,**and `factorial`**.**

* `sum`accepts two integers `a` and `b` and returns `a + b`. Assume that if a value has already been cached for the arguments `(b, a)` where `a != b`, it cannot be used for the arguments `(a, b)`. For example, if the arguments are `(3, 2)` and `(2, 3)`, two separate calls should be made.
* `fib`accepts a single integer `n` and returns `1` if `n <= 1` or `fib(n - 1) + fib(n - 2)` otherwise.
* `factorial` accepts a single integer `n` and returns `1` if `n <= 1` or `factorial(n - 1) * n` otherwise.

**Example 1:**

```
Input:
fnName = "sum"
actions = ["call","call","getCallCount","call","getCallCount"]
values = [[2,2],[2,2],[],[1,2],[]]
Output: [4,4,1,3,2]
Explanation:
const sum = (a, b) => a + b;
const memoizedSum = memoize(sum);
memoizedSum(2, 2); // "call" - returns 4. sum() was called as (2, 2) was not seen before.
memoizedSum(2, 2); // "call" - returns 4. However sum() was not called because the same inputs were seen before.
// "getCallCount" - total call count: 1
memoizedSum(1, 2); // "call" - returns 3. sum() was called as (1, 2) was not seen before.
// "getCallCount" - total call count: 2
```

**Example 2:**

```
Input:
fnName = "factorial"
actions = ["call","call","call","getCallCount","call","getCallCount"]
values = [[2],[3],[2],[],[3],[]]
Output: [2,6,2,2,6,2]
Explanation:
const factorial = (n) => (n <= 1) ? 1 : (n * factorial(n - 1));
const memoFactorial = memoize(factorial);
memoFactorial(2); // "call" - returns 2.
memoFactorial(3); // "call" - returns 6.
memoFactorial(2); // "call" - returns 2. However factorial was not called because 2 was seen before.
// "getCallCount" - total call count: 2
memoFactorial(3); // "call" - returns 6. However factorial was not called because 3 was seen before.
// "getCallCount" - total call count: 2
```

**Example 3:**

```
Input:
fnName = "fib"
actions = ["call","getCallCount"]
values = [[5],[]]
Output: [8,1]
Explanation:
fib(5) = 8 // "call"
// "getCallCount" - total call count: 1
```

**Constraints:**

* `0 <= a, b <= 105`
* `1 <= n <= 10`
* `1 <= actions.length <= 105`
* `actions.length === values.length`
* `actions[i]` is one of "call" and "getCallCount"
* `fnName` is one of "sum", "factorial" and "fib"

---

## Solution & Editorial
# Intuition
Memoization is a classic optimization technique used to speed up computer programs by storing the results of expensive function calls and returning the cached result when the same inputs occur again. Since the problem requires tracking function calls and caching results based on input arguments, a hash map is the ideal data structure to provide $O(1)$ average-time lookups.

# Approach
1. **State Management**: We maintain a `std::map` (or `std::unordered_map`) to store the mapping from input arguments to the computed result. 
2. **Key Generation**: Since the input functions accept either one or two integers, we represent the input as a `std::vector<int>`. This vector serves as a unique key for the map.
3. **Execution Flow**: 
   - When `call` is invoked, we construct a key from the provided arguments.
   - We check if the key exists in our cache.
   - If it exists, return the cached value.
   - If not, execute the original function `fn`, store the result in the cache, increment the call counter, and return the result.

### Visual Trace (Example 1: `sum`)
| Action | Input | Cache State | Result | Call Count |
| :--- | :--- | :--- | :--- | :--- |
| call | (2, 2) | {(2,2): 4} | 4 | 1 |
| call | (2, 2) | {(2,2): 4} | 4 | 1 |
| getCallCount | - | {(2,2): 4} | 1 | 1 |
| call | (1, 2) | {(2,2): 4, (1,2): 3} | 3 | 2 |
| getCallCount | - | {(2,2): 4, (1,2): 3} | 2 | 2 |

# Complexity
- **Time complexity**: $O(1)$ on average per call, assuming the hash map operations (insertion and lookup) are constant time. The actual function execution is only performed once per unique input set.
- **Space complexity**: $O(N)$, where $N$ is the number of unique input sets provided to the memoized function, as we store each unique result in the map.

# Code
```cpp
function memoize(fn) {
    const cache = {};
    
    return function(...args) {
        const key = JSON.stringify(args);
        if (key in cache) {
            return cache[key];
        }
        const result = fn(...args);
        
        cache[key] = result;
        
        return result;
    }
}

/** * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 * return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
```
