# [3464. Maximize the Distance Between Points on a Square](https://leetcode.com/problems/maximize-the-distance-between-points-on-a-square/)
**Difficulty:** `Hard` | **Tags:** `array`, `math`, `binary-search`, `geometry`, `sorting`

---

## Problem Description
You are given an integer `side`, representing the edge length of a square with corners at `(0, 0)`, `(0, side)`, `(side, 0)`, and `(side, side)` on a Cartesian plane.

You are also given a **positive** integer `k` and a 2D integer array `points`, where `points[i] = [xi, yi]` represents the coordinate of a point lying on the **boundary** of the square.

You need to select `k` elements among `points` such that the **minimum** Manhattan distance between any two points is **maximized**.

Return the **maximum** possible **minimum** Manhattan distance between the selected `k` points.

The Manhattan Distance between two cells `(xi, yi)` and `(xj, yj)` is `|xi - xj| + |yi - yj|`.

**Example 1:**

**Input:** side = 2, points = [[0,2],[2,0],[2,2],[0,0]], k = 4

**Output:** 2

**Explanation:**

Select all four points.

**Example 2:**

**Input:** side = 2, points = [[0,0],[1,2],[2,0],[2,2],[2,1]], k = 4

**Output:** 1

**Explanation:**

Select the points `(0, 0)`, `(2, 0)`, `(2, 2)`, and `(2, 1)`.

**Example 3:**

**Input:** side = 2, points = [[0,0],[0,1],[0,2],[1,2],[2,0],[2,2],[2,1]], k = 5

**Output:** 1

**Explanation:**

Select the points `(0, 0)`, `(0, 1)`, `(0, 2)`, `(1, 2)`, and `(2, 2)`.

**Constraints:**

* `1 <= side <= 109`
* `4 <= points.length <= min(4 * side, 15 * 103)`
* `points[i] == [xi, yi]`
* The input is generated such that:
  + `points[i]` lies on the boundary of the square.
  + All `points[i]` are **unique**.
* `4 <= k <= min(25, points.length)`

---

## Solution & Editorial
# Intuition
Since we need to maximize the minimum Manhattan distance between $k$ points on the boundary of a square, this is a classic "maximize the minimum" problem, which suggests a binary search on the answer. The boundary of a square can be linearized into a 1D line of length $4 \times \text{side}$. By mapping each point $(x, y)$ to a single coordinate $p \in [0, 4 \times \text{side})$, the Manhattan distance between two points on the boundary is equivalent to their distance along the perimeter (with wrap-around handling).

# Approach
1. **Linearization**: Map each point $(x, y)$ to a 1D coordinate $p$ based on its position on the perimeter (bottom, right, top, left edges). Sort these coordinates.
2. **Binary Search**: The search space for the distance $d$ is $[0, 2 \times \text{side}]$. For a fixed $d$, we check if it's possible to select $k$ points such that every adjacent pair has a distance $\ge d$.
3. **Binary Lifting**: To efficiently check if $k$ points can be selected, we precompute a jump table `up[step][i]` where `up[0][i]` is the index of the first point at distance $\ge d$ from point $i$. Using binary lifting, we can jump $k$ steps in $O(\log k)$ time to see if we can complete a full cycle within the perimeter.

### Visual Trace (Example 2: side=2, k=4)
- Perimeter length = 8. Points mapped to: `[0, 2, 4, 6, 7]`.
- For $d=1$, we check if we can pick 4 points. Starting at index 0, we jump to the next point $\ge 0+1$, then $\ge 1+1$, etc. If the total distance covered by $k$ jumps is $\le 8$, the condition holds.

# Complexity
- Time complexity: $$O(N \log N + \log(\text{side}) \cdot N \log K)$$, where $N$ is the number of points. Sorting takes $O(N \log N)$, and the binary search runs for $O(\log(\text{side}))$ iterations, each performing binary lifting in $O(N \log K)$.
- Space complexity: $$O(N \log K)$$ to store the binary lifting table `up`.

# Code
```cpp
class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        if (k == 2) {
            long long max_sum = -4e18, min_sum = 4e18;
            long long max_diff = -4e18, min_diff = 4e18;
            for (const auto& pt : points) {
                long long sum = (long long)pt[0] + pt[1];
                long long diff = (long long)pt[0] - pt[1];
                max_sum = max(max_sum, sum);
                min_sum = min(min_sum, sum);
                max_diff = max(max_diff, diff);
                min_diff = min(min_diff, diff);
            }
            return max(max_sum - min_sum, max_diff - min_diff);
        }

        vector<long long> p;
        for (const auto& pt : points) {
            long long x = pt[0], y = pt[1];
            if (y == 0) p.push_back(x);
            else if (x == side) p.push_back(side + y);
            else if (y == side) p.push_back(3LL * side - x);
            else p.push_back(4LL * side - y);
        }

        sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());
        int n = p.size();
        
        if (n < k) return 0;

        int LOG = 0;
        while ((1 << LOG) <= k) LOG++;
        vector<long long> p2(2 * n);
        for (int i = 0; i < n; ++i) {
            p2[i] = p[i];
            p2[i + n] = p[i] + 4LL * side;
        }
        auto check = [&](long long d) {
            vector<int> nxt(2 * n + 1, 2 * n);
            int j = 0;
            
            for (int i = 0; i < 2 * n; ++i) {
                while (j < 2 * n && p2[j] - p2[i] < d) {
                    j++;
                }
                nxt[i] = j;
            }

            vector<vector<int>> up(LOG, vector<int>(2 * n + 1, 2 * n));
            for (int i = 0; i <= 2 * n; ++i) up[0][i] = nxt[i];

            for (int step = 1; step < LOG; ++step) {
                for (int i = 0; i <= 2 * n; ++i) {
                    up[step][i] = up[step - 1][up[step - 1][i]];
                }
            }

            for (int i = 0; i < n; ++i) {
                int curr = i; 
                for (int step = 0; step < LOG; ++step) {
                    if ((k >> step) & 1) {
                        curr = up[step][curr];
                    }
                }
                if (curr <= i + n) return true;
            }
            return false;
        };

        long long low = 0, high = 2e9; 
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }

        return ans;
    }
};
```
