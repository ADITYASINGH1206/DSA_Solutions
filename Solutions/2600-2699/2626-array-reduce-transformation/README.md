# [2626. Array Reduce Transformation](https://leetcode.com/problems/array-reduce-transformation/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
Given an integer array `nums`, a reducer function `fn`, and an initial value `init`, return the final result obtained by executing the `fn` function on each element of the array, sequentially, passing in the return value from the calculation on the preceding element.

This result is achieved through the following operations: `val = fn(init, nums[0]), val = fn(val, nums[1]), val = fn(val, nums[2]), ...` until every element in the array has been processed. The ultimate value of `val` is then returned.

If the length of the array is 0, the function should return `init`.

Please solve it without using the built-in `Array.reduce` method.

**Example 1:**

```
Input: 
nums = [1,2,3,4]
fn = function sum(accum, curr) { return accum + curr; }
init = 0
Output: 10
Explanation:
initially, the value is init=0.
(0) + nums[0] = 1
(1) + nums[1] = 3
(3) + nums[2] = 6
(6) + nums[3] = 10
The final answer is 10.
```

**Example 2:**

```
Input: 
nums = [1,2,3,4]
fn = function sum(accum, curr) { return accum + curr * curr; }
init = 100
Output: 130
Explanation:
initially, the value is init=100.
(100) + nums[0] * nums[0] = 101
(101) + nums[1] * nums[1] = 105
(105) + nums[2] * nums[2] = 114
(114) + nums[3] * nums[3] = 130
The final answer is 130.
```

**Example 3:**

```
Input: 
nums = []
fn = function sum(accum, curr) { return 0; }
init = 25
Output: 25
Explanation: For empty arrays, the answer is always init.
```

**Constraints:**

* `0 <= nums.length <= 1000`
* `0 <= nums[i] <= 1000`
* `0 <= init <= 1000`

---

## Solution & Editorial
# Intuition
The problem requires us to perform a sequential transformation across an array, where each step depends on the result of the previous one. This is a classic "fold" or "reduce" operation, which can be implemented efficiently using a simple iterative loop.

# Approach
1. Initialize a variable `ans` with the provided `init` value.
2. Iterate through each element `nums[i]` in the input array.
3. In each iteration, update `ans` by applying the reducer function `fn` to the current `ans` and the current element `nums[i]`.
4. After the loop completes, return `ans`. If the array is empty, the loop is skipped, and `init` is returned correctly.

### Visual Trace (Example 1: nums=[1,2,3,4], init=0)
| Iteration | Current Element | Operation | Result (ans) |
| :--- | :--- | :--- | :--- |
| Initial | - | - | 0 |
| 1 | 1 | fn(0, 1) | 1 |
| 2 | 2 | fn(1, 2) | 3 |
| 3 | 3 | fn(3, 3) | 6 |
| 4 | 4 | fn(6, 4) | 10 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array, as we visit each element exactly once.
- Space complexity: $$O(1)$$, as we only use a single variable to store the running accumulator.

# Code
```cpp
/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let ans = init;
    for(let i =0;i<nums.length;++i){
        ans = fn(ans,nums[i]);
    }
    return ans;
};
```
