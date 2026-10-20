# [1436. Destination City](https://leetcode.com/problems/destination-city/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `string`

---

## Problem Description
You are given the array `paths`, where `paths[i] = [cityAi, cityBi]` means there exists a direct path going from `cityAi` to `cityBi`. *Return the destination city, that is, the city without any path outgoing to another city.*

It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

**Example 1:**

```
Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo" 
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
```

**Example 2:**

```
Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are: 
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
Clearly the destination city is "A".
```

**Example 3:**

```
Input: paths = [["A","Z"]]
Output: "Z"
```

**Constraints:**

* `1 <= paths.length <= 100`
* `paths[i].length == 2`
* `1 <= cityAi.length, cityBi.length <= 10`
* `cityAi != cityBi`
* All strings consist of lowercase and uppercase English letters and the space character.

---

## Solution & Editorial
# Intuition
The problem asks us to find a city that appears as a destination but never as a starting point. Since every path is defined as `[source, destination]`, the destination city is simply the unique element present in the set of all destination cities that is not present in the set of all source cities.

# Approach
1. Initialize two sets: `first` to store all source cities and `second` to store all destination cities.
2. Iterate through the `paths` array. For each path `[cityA, cityB]`, insert `cityA` into `first` and `cityB` into `second`.
3. Iterate through every city in the `second` set. If a city is not found in the `first` set, it must be the destination city.

### Visual Trace (Example 1: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]])
| Iteration | Path | first (Sources) | second (Destinations) |
| :--- | :--- | :--- | :--- |
| 1 | ["London", "New York"] | {"London"} | {"New York"} |
| 2 | ["New York", "Lima"] | {"London", "New York"} | {"New York", "Lima"} |
| 3 | ["Lima", "Sao Paulo"] | {"London", "New York", "Lima"} | {"New York", "Lima", "Sao Paulo"} |

Final check: "New York" is in `first`, "Lima" is in `first`, "Sao Paulo" is NOT in `first`. Return "Sao Paulo".

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N$$ is the number of paths. We perform $$2N$$ insertions into sets, each taking $$O(\log N)$$ time, followed by a linear scan of the destination set.
- Space complexity: $$O(N)$$, as we store at most $$2N$$ city names in our sets.

# Code
```cpp
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> first;
        set<string> second;
        int n = paths.size();
        for(int i =0;i<n;i++){
            first.insert(paths[i][0]);
            second.insert(paths[i][1]);
        }

        for (const string& city : second) {
            if (first.find(city) == first.end()) {
                return city;
            }
        }
        return "";
        
    }
};
```
