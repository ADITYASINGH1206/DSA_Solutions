# [2722. Join Two Arrays by ID](https://leetcode.com/problems/join-two-arrays-by-id/)
**Difficulty:** `Medium` | **Tags:** `Algorithm`

---

## Problem Description
Given two arrays `arr1` and `arr2`, return a new array `joinedArray`. All the objects in each of the two inputs arrays will contain an `id` field that has an integer value.

`joinedArray` is an array formed by merging `arr1` and `arr2` based on their `id` key. The length of `joinedArray` should be the length of unique values of `id`. The returned array should be sorted in **ascending** order based on the `id` key.

If a given `id` exists in one array but not the other, the single object with that `id` should be included in the result array without modification.

If two objects share an `id`, their properties should be merged into a single object:

* If a key only exists in one object, that single key-value pair should be included in the object.
* If a key is included in both objects, the value in the object from `arr2` should override the value from `arr1`.

**Example 1:**

```
Input: 
arr1 = [
    {"id": 1, "x": 1},
    {"id": 2, "x": 9}
], 
arr2 = [
    {"id": 3, "x": 5}
]
Output: 
[
    {"id": 1, "x": 1},
    {"id": 2, "x": 9},
    {"id": 3, "x": 5}
]
Explanation: There are no duplicate ids so arr1 is simply concatenated with arr2.
```

**Example 2:**

```
Input: 
arr1 = [
    {"id": 1, "x": 2, "y": 3},
    {"id": 2, "x": 3, "y": 6}
], 
arr2 = [
    {"id": 2, "x": 10, "y": 20},
    {"id": 3, "x": 0, "y": 0}
]
Output: 
[
    {"id": 1, "x": 2, "y": 3},
    {"id": 2, "x": 10, "y": 20},
    {"id": 3, "x": 0, "y": 0}
]
Explanation: The two objects with id=1 and id=3 are included in the result array without modifiction. The two objects with id=2 are merged together. The keys from arr2 override the values in arr1.
```

**Example 3:**

```
Input: 
arr1 = [
    {"id": 1, "b": {"b": 94},"v": [4, 3], "y": 48}
]
arr2 = [
    {"id": 1, "b": {"c": 84}, "v": [1, 3]}
]
Output: [
    {"id": 1, "b": {"c": 84}, "v": [1, 3], "y": 48}
]
Explanation: The two objects with id=1 are merged together. For the keys "b" and "v" the values from arr2 are used. Since the key "y" only exists in arr1, that value is taken form arr1.
```

**Constraints:**

* `arr1` and `arr2` are valid JSON arrays
* Each object in `arr1` and `arr2` has a unique integer `id` key
* `2 <= JSON.stringify(arr1).length <= 106`
* `2 <= JSON.stringify(arr2).length <= 106`

---

## Solution & Editorial
# Intuition
To efficiently join two arrays based on a unique `id`, we need a data structure that provides $O(1)$ average time complexity for lookups and insertions. A hash map (specifically `std::map` or `std::unordered_map`) is ideal for mapping `id` values to their corresponding objects. By iterating through both arrays and updating the map, we can handle merging logic (overwriting values from `arr2`) in a single pass.

# Approach
1. Initialize a `std::map<int, Object>` to store the merged results. Using `std::map` ensures that the final iteration over the map yields objects sorted by `id` in ascending order automatically.
2. Iterate through `arr1` and insert each object into the map using its `id` as the key.
3. Iterate through `arr2`. For each object, check if the `id` already exists in the map:
   - If it exists, merge the properties of the current object into the existing one (overwriting existing keys with values from `arr2`).
   - If it does not exist, simply insert the object into the map.
4. Collect all objects from the map into a result vector.

### Visual Trace (Example 2)
| Step | Action | Map State (id -> object) |
| :--- | :--- | :--- |
| 1 | Process `arr1` | `{1: {x:2, y:3}, 2: {x:3, y:6}}` |
| 2 | Process `arr2` (id 2) | `{1: {x:2, y:3}, 2: {x:10, y:20}}` |
| 3 | Process `arr2` (id 3) | `{1: {x:2, y:3}, 2: {x:10, y:20}, 3: {x:0, y:0}}` |

# Complexity
- Time complexity: $$O((N+M) \log K)$$, where $N$ and $M$ are the lengths of `arr1` and `arr2`, and $K$ is the number of unique IDs. The map operations take logarithmic time, and we iterate through all elements once.
- Space complexity: $$O(K)$$, where $K$ is the number of unique IDs stored in the map.

# Code
```cpp
function join(arr1: ArrayType[], arr2: ArrayType[]): ArrayType[] {
    const r = (acc: Obj, x: ArrayType): Obj => ((acc[x.id] = x), acc);
    const d = arr1.reduce(r, {});

    arr2.forEach(x => {
        if (d[x.id]) {
            Object.assign(d[x.id], x);
        } else {
            d[x.id] = x;
        }
    });
    return Object.values(d);
}

type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type ArrayType = { id: number } & Record<string, JSONValue>;

type Obj = Record<number, ArrayType>;
```
