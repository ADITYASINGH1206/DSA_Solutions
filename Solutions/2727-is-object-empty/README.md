# [2727. Is Object Empty](https://leetcode.com/problems/is-object-empty/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
Given an object or an array, return if it is empty.

* An empty object contains no key-value pairs.
* An empty array contains no elements.

You may assume the object or array is the output of `JSON.parse`.

**Example 1:**

```
Input: obj = {"x": 5, "y": 42}
Output: false
Explanation: The object has 2 key-value pairs so it is not empty.
```

**Example 2:**

```
Input: obj = {}
Output: true
Explanation: The object doesn't have any key-value pairs so it is empty.
```

**Example 3:**

```
Input: obj = [null, false, 0]
Output: false
Explanation: The array has 3 elements so it is not empty.
```

**Constraints:**

* `obj` is a valid JSON object or array
* `2 <= JSON.stringify(obj).length <= 105`

**Can you solve it in O(1) time?**

---

## Solution & Editorial
# Intuition
To determine if a JSON object or array is empty, we only need to verify if it contains at least one enumerable property. If we can successfully iterate over the object at least once, it is not empty.

# Approach
1. Use a `for...in` loop to iterate over the keys of the input `obj`.
2. If the loop enters the body even once, it implies the object has at least one key-value pair or array element; return `false` immediately.
3. If the loop completes without executing the body, the object is empty; return `true`.

### Visual Trace (Example 1: `obj = {"x": 5, "y": 42}`)
| Iteration | Key Found | Action | Result |
| :--- | :--- | :--- | :--- |
| 1 | "x" | Return `false` | `false` |

### Visual Trace (Example 2: `obj = {}`)
| Iteration | Key Found | Action | Result |
| :--- | :--- | :--- | :--- |
| 1 | None | Loop terminates | `true` |

# Complexity
- Time complexity: $$O(1)$$. We only check for the existence of the first element. The loop terminates as soon as the first key is encountered, regardless of the total size of the object.
- Space complexity: $$O(1)$$. No additional data structures are allocated; we only use a constant amount of space for the loop iterator.

# Code
```cpp
/**
 * @param {Object | Array} obj
 * @return {boolean}
 */
var isEmpty = function (obj) {
    for (const x in obj) {
        return false;
    }
    return true;
};
```
