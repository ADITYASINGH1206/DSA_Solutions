# [2622. Cache With Time Limit](https://leetcode.com/problems/cache-with-time-limit/)
**Difficulty:** `Medium` | **Tags:** `Algorithm`

---

## Problem Description
Write a class that allows getting and setting key-value pairs, however a **time until expiration** is associated with each key.

The class has three public methods:

`set(key, value, duration)`: accepts an integer `key`, an integer `value`, and a `duration` in milliseconds. Once the `duration` has elapsed, the key should be inaccessible. The method should return `true` if the same un-expired key already exists and `false` otherwise. Both the value and duration should be overwritten if the key already exists.

`get(key)`: if an un-expired key exists, it should return the associated value. Otherwise it should return `-1`.

`count()`: returns the count of un-expired keys.

**Example 1:**

```
Input: 
actions = ["TimeLimitedCache", "set", "get", "count", "get"]
values = [[], [1, 42, 100], [1], [], [1]]
timeDelays = [0, 0, 50, 50, 150]
Output: [null, false, 42, 1, -1]
Explanation:
At t=0, the cache is constructed.
At t=0, a key-value pair (1: 42) is added with a time limit of 100ms. The value doesn't exist so false is returned.
At t=50, key=1 is requested and the value of 42 is returned.
At t=50, count() is called and there is one active key in the cache.
At t=100, key=1 expires.
At t=150, get(1) is called but -1 is returned because the cache is empty.
```

**Example 2:**

```
Input: 
actions = ["TimeLimitedCache", "set", "set", "get", "get", "get", "count"]
values = [[], [1, 42, 50], [1, 50, 100], [1], [1], [1], []]
timeDelays = [0, 0, 40, 50, 120, 200, 250]
Output: [null, false, true, 50, 50, -1, 0]
Explanation:
At t=0, the cache is constructed.
At t=0, a key-value pair (1: 42) is added with a time limit of 50ms. The value doesn't exist so false is returned.
At t=40, a key-value pair (1: 50) is added with a time limit of 100ms. A non-expired value already existed so true is returned and the old value was overwritten.
At t=50, get(1) is called which returned 50.
At t=120, get(1) is called which returned 50.
At t=140, key=1 expires.
At t=200, get(1) is called but the cache is empty so -1 is returned.
At t=250, count() returns 0 because the cache is empty.
```

**Constraints:**

* `0 <= key, value <= 109`
* `0 <= duration <= 1000`
* `1 <= actions.length <= 100`
* `actions.length === values.length`
* `actions.length === timeDelays.length`
* `0 <= timeDelays[i] <= 1450`
* `actions[i]` is one of "TimeLimitedCache", "set", "get" and "count"
* First action is always "TimeLimitedCache" and must be executed immediately, with a 0-millisecond delay

---

## Solution & Editorial
# Intuition
The problem requires managing key-value pairs where each entry has an associated expiration timestamp. Since we need to perform lookups, insertions, and updates efficiently, a hash map is the ideal data structure. The core logic relies on comparing the current system time against the stored expiration time for each key.

# Approach
1. **Data Structure**: Use `std::unordered_map<int, std::pair<int, long long>>` to store the mapping from `key` to a pair containing the `value` and the `expiry_time` (calculated as `current_time + duration`).
2. **`set(key, value, duration)`**: 
   - Check if the key exists and is not expired.
   - Update the map with the new value and `chrono::steady_clock::now() + duration`.
   - Return `true` if the key existed (regardless of expiration status), otherwise `false`.
3. **`get(key)`**: 
   - Check if the key exists in the map.
   - Verify if the current time is less than the stored `expiry_time`.
   - If valid, return the value; otherwise, return `-1`.
4. **`count()`**: 
   - Iterate through the map and count entries where the current time is less than the `expiry_time`.

### Visual Trace (Example 1)
| Time | Action | State (Key: {Value, Expiry}) | Result |
| :--- | :--- | :--- | :--- |
| 0 | set(1, 42, 100) | {1: {42, 100}} | false |
| 50 | get(1) | {1: {42, 100}} | 42 |
| 50 | count() | {1: {42, 100}} | 1 |
| 150 | get(1) | {1: {42, 100}} | -1 |

# Complexity
- Time complexity: $$O(1)$$ for `set` and `get` on average, as hash map operations are constant time. `count` is $$O(N)$$ where $$N$$ is the number of keys in the cache.
- Space complexity: $$O(N)$$ to store the key-value pairs and their associated timestamps.

# Code
```cpp
class TimeLimitedCache {
    #cache: Map<number, [value: number, expire: number]> = new Map();

    set(key: number, value: number, duration: number): boolean {
        const isExist = this.#cache.has(key);

        if (!this.#isExpired(key)) {
            this.#cache.set(key, [value, Date.now() + duration]);
        }

        return isExist;
    }

    get(key: number): number {
        if (this.#isExpired(key)) return -1;
        const res = this.#cache.get(key)?.[0] ?? -1;
        return res;
    }

    count(): number {
        const xs = Array.from(this.#cache).filter(([key]) => !this.#isExpired(key));
        return xs.length;
    }

    #isExpired = (key: number) =>
        this.#cache.has(key) &&
        (this.#cache.get(key)?.[1] ?? Number.NEGATIVE_INFINITY) < Date.now();
}

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */
```
