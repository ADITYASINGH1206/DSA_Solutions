# [2705. Compact Object](https://leetcode.com/problems/compact-object/)
**Difficulty:** `Medium` | **Tags:** `Algorithm`

---

## Problem Description
Given an object or array `obj`, return a **compact object**.

A **compact object** is the same as the original object, except with keys containing **falsy** values removed. This operation applies to the object and any nested objects. Arrays are considered objects where the indices are keys. A value is considered **falsy** when `Boolean(value)` returns `false`.

You may assume the `obj` is the output of `JSON.parse`. In other words, it is valid JSON.

**Example 1:**

```
Input: obj = [null, 0, false, 1]
Output: [1]
Explanation: All falsy values have been removed from the array.
```

**Example 2:**

```
Input: obj = {"a": null, "b": [false, 1]}
Output: {"b": [1]}
Explanation: obj["a"] and obj["b"][0] had falsy values and were removed.
```

**Example 3:**

```
Input: obj = [null, 0, 5, [0], [false, 16]]
Output: [5, [], [16]]
Explanation: obj[0], obj[1], obj[3][0], and obj[4][0] were falsy and removed.
```

**Constraints:**

* `obj` is a valid JSON object
* `2 <= JSON.stringify(obj).length <= 106`

---

## Solution & Editorial
# Intuition
The problem requires a deep traversal of a JSON-like structure to prune all falsy values. Since the structure can be nested arbitrarily, a recursive approach is the most natural way to process each node, ensuring that nested objects and arrays are compacted before their parent containers are finalized.

# Approach
1. **Base Case**: If the input `obj` is not an object (i.e., a primitive like a number, string, or boolean) or is `null`, return it directly. Note that in the context of this problem, we only remove falsy values at the container level.
2. **Array Handling**: If `obj` is an array, use a filter to remove all falsy elements. Then, map over the remaining elements, recursively calling `compactObject` on each to ensure nested structures are also compacted.
3. **Object Handling**: If `obj` is an object, iterate through its key-value pairs. For every value that evaluates to truthy, recursively compact it and assign it to a new result object.

### Visual Trace (Example 3: `[null, 0, 5, [0], [false, 16]]`)
| Step | Input | Action | Result |
| :--- | :--- | :--- | :--- |
| 1 | `[null, 0, 5, [0], [false, 16]]` | Filter falsy | `[5, [0], [false, 16]]` |
| 2 | `5` | Base case | `5` |
| 3 | `[0]` | Filter falsy | `[]` |
| 4 | `[false, 16]` | Filter falsy | `[16]` |
| 5 | Final | Combine | `[5, [], [16]]` |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the total number of elements and keys in the JSON structure. Each node is visited exactly once.
- Space complexity: $$O(D)$$, where $$D$$ is the maximum depth of the object, representing the recursion stack space.

# Code
```cpp
/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function (obj) {
    if (!obj || typeof obj !== 'object') {
        return obj;
    }
    if (Array.isArray(obj)) {
        return obj.filter(Boolean).map(compactObject);
    }
    return Object.entries(obj).reduce((acc, [key, value]) => {
        if (value) {
            acc[key] = compactObject(value);
        }
        return acc;
    }, {});
};
```
