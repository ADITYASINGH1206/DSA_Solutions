# [2418. Sort the People](https://leetcode.com/problems/sort-the-people/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `string`, `sorting`

---

## Problem Description
You are given an array of strings `names`, and an array `heights` that consists of **distinct** positive integers. Both arrays are of length `n`.

For each index `i`, `names[i]` and `heights[i]` denote the name and height of the `ith` person.

Return `names` *sorted in **descending** order by the people's heights*.

**Example 1:**

```
Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.
```

**Example 2:**

```
Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.
```

**Constraints:**

* `n == names.length == heights.length`
* `1 <= n <= 103`
* `1 <= names[i].length <= 20`
* `1 <= heights[i] <= 105`
* `names[i]` consists of lower and upper case English letters.
* All the values of `heights` are distinct.

---

## Solution & Editorial
# Intuition
Since we need to associate names with their corresponding heights and sort the names based on those heights, a key-value mapping is the most natural data structure. By using a map, we can store heights as keys and names as values, leveraging the map's inherent ability to keep keys in sorted order.

# Approach
1. Initialize a `std::map<int, string> mp` to store height-name pairs. Because `std::map` is ordered by keys by default, inserting all pairs will automatically sort them by height in ascending order.
2. Iterate through the `names` and `heights` arrays using a loop, populating the map with `mp[heights[i]] = names[i]`.
3. Create a result vector `v`. Iterate through the map in reverse order using a reverse iterator (`rbegin()` to `rend()`) to extract the names corresponding to heights from largest to smallest.
4. Return the vector `v`.

### Visual Trace (Example 1: names = ["Mary","John","Emma"], heights = [180,165,170])
| Step | Action | Map State (Key: Height, Value: Name) |
| :--- | :--- | :--- |
| 1 | Insert (180, "Mary") | {180: "Mary"} |
| 2 | Insert (165, "John") | {165: "John", 180: "Mary"} |
| 3 | Insert (170, "Emma") | {165: "John", 170: "Emma", 180: "Mary"} |
| 4 | Reverse Iterate | "Mary" -> "Emma" -> "John" |

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N$$ is the number of people. Each insertion into the `std::map` takes $$O(\log N)$$ time, and we perform this $$N$$ times. The final traversal takes $$O(N)$$.
- Space complexity: $$O(N)$$, as we store all $$N$$ elements in the map and the result vector.

# Code
```cpp
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> mp;
        vector<string> v;
        for(int i = 0; i < names.size(); i++) {
            mp[heights[i]] = names[i];
        }
        for (auto i = mp.rbegin(); i != mp.rend(); ++i) {
            v.push_back(i->second);
        }
        
        return v;
    }
};
```
