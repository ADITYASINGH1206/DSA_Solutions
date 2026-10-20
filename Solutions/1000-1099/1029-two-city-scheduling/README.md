# [1029. Two City Scheduling](https://leetcode.com/problems/two-city-scheduling/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `sorting`, `hungarian-algorithm`, `successive-shortest-path-algorithm`

---

## Problem Description
A company is planning to interview `2n` people. Given the array `costs` where `costs[i] = [aCosti, bCosti]`, the cost of flying the `ith` person to city `a` is `aCosti`, and the cost of flying the `ith` person to city `b` is `bCosti`.

Return *the minimum cost to fly every person to a city* such that exactly `n` people arrive in each city.

**Example 1:**

```
Input: costs = [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
```

**Example 2:**

```
Input: costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
Output: 1859
```

**Example 3:**

```
Input: costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
Output: 3086
```

**Constraints:**

* `2 * n == costs.length`
* `2 <= costs.length <= 100`
* `costs.length` is even.
* `1 <= aCosti, bCosti <= 1000`

---

## Solution & Editorial
# Intuition
The problem requires us to send exactly $n$ people to City A and $n$ people to City B out of $2n$ total people, minimizing the total cost. Initially, we can assume everyone is sent to City A, accumulating all `aCost` values. To optimize, we need to choose which $n$ people should be redirected to City B. The relative savings of sending person $i$ to City B instead of City A is given by `bCost[i] - aCost[i]`, or equivalently, sending to City A instead of City B is determined by `aCost[i] - bCost[i]`. By sorting the people based on how much more expensive City A is compared to City B, we can greedily pick the best candidates for each city.

# Approach
1. Sort the `costs` array based on the relative cost difference `(v1[0] - v1[1] < v2[0] - v2[1])`. This places individuals who benefit most from going to City A at the beginning of the array, and those who benefit most from going to City B at the end.
2. Iterate through the first half of the sorted array ($i$ from $0$ to $rac{N}{2} - 1$) and add their City A costs (`costs[i][0]`).
3. Iterate through the second half of the sorted array ($i$ from $rac{N}{2}$ to $N - 1$) and add their City B costs (`costs[i + costs.size() / 2][1]`).
4. Accumulate and return the total minimum cost stored in `res`.

### Visual Trace Walkthrough (Example 1)
Given `costs = [[10,20],[30,200],[400,50],[30,20]]` ($N=4$, $n=2$):
- Calculate `aCost - bCost` for each person:
  - Person 0: $10 - 20 = -10$
  - Person 1: $30 - 200 = -170$
  - Person 2: $400 - 50 = 350$
  - Person 3: $30 - 20 = 10$
- Sorted order by `aCost - bCost` ascending:
  1. `[30, 200]` ($30-200 = -170$)
  2. `[10, 20]` ($10-20 = -10$)
  3. `[30, 20]` ($30-20 = 10$)
  4. `[400, 50]` ($400-50 = 350$)
- First half ($i < 2$) goes to City A: take `30` and `10` $ightarrow$ Total: $40$
- Second half ($i \ge 2$) goes to City B: take `20` and `50` $ightarrow$ Total: $70$
- Final Result: $40 + 70 = 110$.

# Complexity
- Time complexity: $$O(N \log N)$$ where $N$ is the total number of people ($2n$). The complexity is dominated by sorting the `costs` array of size $N$. The linear scan takes $$O(N)$$ time.
- Space complexity: $$O(1)$$ auxiliary space, as sorting is performed in-place and only a constant number of variables are used.

# Code
```cpp
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs, int res = 0) {
    sort(costs.begin(), costs.end(), [](vector<int> &v1, vector<int> &v2) {
        return (v1[0] - v1[1] < v2[0] - v2[1]);
    });
    for (int i = 0; i < costs.size() / 2; ++i) {
        res += costs[i][0] + costs[i + costs.size() / 2][1];
    }
    return res;
    }
};
```
