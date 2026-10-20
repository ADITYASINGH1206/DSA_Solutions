# [705. Design HashSet](https://leetcode.com/problems/design-hashset/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `linked-list`, `design`, `hash-function`

---

## Problem Description
Design a HashSet without using any built-in hash table libraries.

Implement `MyHashSet` class:

* `void add(key)` Inserts the value `key` into the HashSet.
* `bool contains(key)` Returns whether the value `key` exists in the HashSet or not.
* `void remove(key)` Removes the value `key` in the HashSet. If `key` does not exist in the HashSet, do nothing.

**Example 1:**

```
Input
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
Output
[null, null, null, true, false, null, true, null, false]

Explanation
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)
```

**Constraints:**

* `0 <= key <= 106`
* At most `104` calls will be made to `add`, `remove`, and `contains`.

---

## Solution & Editorial
# Intuition
Since the maximum possible value of `key` is bounded by $10^6$, we can allocate a boolean array of fixed size $1000001$ to serve as a direct addressing table. Each index in the array directly represents the presence or absence of that specific key in the hash set.

# Approach
1. Initialize a `vector<bool>` named `v` of size $1000001$, with all elements set to `false` in the constructor `MyHashSet()`.
2. For `add(key)`, set the boolean flag at index `key` in `v` to `true`.
3. For `remove(key)`, set the boolean flag at index `key` in `v` to `false`.
4. For `contains(key)`, return the boolean value stored at index `key` in `v`.

### Visual Trace Walkthrough (Example Operations)
- `MyHashSet()` -> `v` allocated with size $1000001$, all `false`.
- `add(1)` -> `v[1] = true`
- `add(2)` -> `v[2] = true`
- `contains(1)` -> returns `v[1]` which is `true`
- `contains(3)` -> returns `v[3]` which is `false`
- `remove(2)` -> `v[2] = false`

# Complexity
- Time complexity: $$O(1)$$ for all operations (`add`, `remove`, and `contains`), as direct array index access takes constant time.
- Space complexity: $$O(N)$$ where $$N = 1000001$$ is the maximum key value limit, storing one bit per key using optimized `vector<bool>` storage.

# Code
```cpp
class MyHashSet {
public:
    vector<bool> v;

    MyHashSet() {
        v = vector<bool>(1000001, false);
    }

    void add(int key) {
        v[key] = true;
    }

    void remove(int key) {
        v[key] = false; 
    }

    bool contains(int key) {
        return v[key]; 
    }
};
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
```
