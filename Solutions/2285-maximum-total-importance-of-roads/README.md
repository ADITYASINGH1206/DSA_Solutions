# [2285. Maximum Total Importance of Roads](https://leetcode.com/problems/maximum-total-importance-of-roads/)
**Difficulty:** `Medium` | **Tags:** `greedy`, `graph`, `sorting`, `heap-priority-queue`

---

## Problem Description
You are given an integer `n` denoting the number of cities in a country. The cities are numbered from `0` to `n - 1`.

You are also given a 2D integer array `roads` where `roads[i] = [ai, bi]` denotes that there exists a **bidirectional** road connecting cities `ai` and `bi`.

You need to assign each city with an integer value from `1` to `n`, where each value can only be used **once**. The **importance** of a road is then defined as the **sum** of the values of the two cities it connects.

Return *the **maximum total importance** of all roads possible after assigning the values optimally.*

**Example 1:**

```
Input: n = 5, roads = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
Output: 43
Explanation: The figure above shows the country and the assigned values of [2,4,5,3,1].
- The road (0,1) has an importance of 2 + 4 = 6.
- The road (1,2) has an importance of 4 + 5 = 9.
- The road (2,3) has an importance of 5 + 3 = 8.
- The road (0,2) has an importance of 2 + 5 = 7.
- The road (1,3) has an importance of 4 + 3 = 7.
- The road (2,4) has an importance of 5 + 1 = 6.
The total importance of all roads is 6 + 9 + 8 + 7 + 7 + 6 = 43.
It can be shown that we cannot obtain a greater total importance than 43.
```

**Example 2:**

```
Input: n = 5, roads = [[0,3],[2,4],[1,3]]
Output: 20
Explanation: The figure above shows the country and the assigned values of [4,3,2,5,1].
- The road (0,3) has an importance of 4 + 5 = 9.
- The road (2,4) has an importance of 2 + 1 = 3.
- The road (1,3) has an importance of 3 + 5 = 8.
The total importance of all roads is 9 + 3 + 8 = 20.
It can be shown that we cannot obtain a greater total importance than 20.
```

**Constraints:**

* `2 <= n <= 5 * 104`
* `1 <= roads.length <= 5 * 104`
* `roads[i].length == 2`
* `0 <= ai, bi <= n - 1`
* `ai != bi`
* There are no duplicate roads.

---

## Solution & Editorial
# Intuition
The total importance of all roads is the sum of the values of the two endpoints for every road. If a city has a degree $d$, its assigned value will be added to the total importance $d$ times. To maximize the total sum, we must assign the largest available values to the cities with the highest degrees.

# Approach
1. Calculate the degree of each city by iterating through the `roads` array and incrementing the count for both endpoints in a `degree` vector.
2. Sort the `degree` vector in non-decreasing order. This aligns the smallest degrees with the smallest available values (1, 2, ...) and the largest degrees with the largest available values (n, n-1, ...).
3. Iterate through the sorted `degree` vector. For each city at index `i` (0-indexed), multiply its degree by `(i + 1)` and add it to the total `ans`. This effectively assigns the value `i + 1` to the city with the `i`-th smallest degree.

### Visual Trace (Example 1: n=5, roads=[[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]])
- Degrees: [0:2, 1:3, 2:4, 3:2, 4:1]
- Sorted Degrees: [1, 2, 2, 3, 4]
- Calculation:
  - i=0: 1 * 1 = 1
  - i=1: 2 * 2 = 4
  - i=2: 2 * 3 = 6
  - i=3: 3 * 4 = 12
  - i=4: 4 * 5 = 20
- Total: 1 + 4 + 6 + 12 + 20 = 43

# Complexity
- Time complexity: $$O(N \log N + E)$$, where $$N$$ is the number of cities and $$E$$ is the number of roads. We iterate over all roads once ($$O(E)$$) and sort the degree array of size $$N$$ ($$O(N \log N)$$).
- Space complexity: $$O(N)$$, required to store the degree of each city.

# Code
```cpp
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n, 0);
        for (const auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        sort(degree.begin(), degree.end());
        
        long long ans = 0;
        for (long long i = 0; i < n; i++) {
            ans += degree[i] * (i + 1);
        }
        
        return ans;
    }
};
```
