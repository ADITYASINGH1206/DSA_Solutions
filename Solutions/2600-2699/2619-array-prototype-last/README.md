# [2619. Array Prototype Last](https://leetcode.com/problems/array-prototype-last/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
Write code that enhances all arrays such that you can call the `array.last()` method on any array and it will return the last element. If there are no elements in the array, it should return `-1`.

You may assume the array is the output of `JSON.parse`.

**Example 1:**

```
Input: nums = [null, {}, 3]
Output: 3
Explanation: Calling nums.last() should return the last element: 3.
```

**Example 2:**

```
Input: nums = []
Output: -1
Explanation: Because there are no elements, return -1.
```

**Constraints:**

* `arr` is a valid JSON array
* `0 <= arr.length <= 1000`

---

## Solution & Editorial
# Intuition
To extend the functionality of all arrays in a JavaScript environment, we leverage the `Array.prototype` object. By attaching a new method `last` to this prototype, every array instance gains access to this function, allowing for a clean, object-oriented approach to retrieving the final element.

# Approach
1. **Prototype Augmentation**: We define `Array.prototype.last` as a function. This ensures that any array instance can invoke `.last()`.
2. **Conditional Logic**: Inside the function, we check the `this.length` property. 
   - If `this.length` is truthy (i.e., greater than 0), the array is non-empty.
   - We use the `at(-1)` method, which is the idiomatic way to access the last element of an array in modern JavaScript.
   - If `this.length` is 0, we return `-1` as per the problem requirements.

### Visual Trace (Example 1: `nums = [null, {}, 3]`)
| Step | Action | State | Result |
| :--- | :--- | :--- | :--- |
| 1 | Call `nums.last()` | `this.length = 3` | - |
| 2 | Check `this.length` | `3 > 0` (True) | - |
| 3 | Return `this.at(-1)` | `nums[2]` | `3` |

# Complexity
- Time complexity: $$O(1)$$ — Accessing the length property and the last element via index is a constant-time operation.
- Space complexity: $$O(1)$$ — No additional data structures are created; we operate directly on the existing array instance.

# Code
```cpp
declare global {
    interface Array<T> {
        last(): T | -1;
    }
}

Array.prototype.last = function () {
    return this.length ? this.at(-1) : -1;
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */

export {};
```
