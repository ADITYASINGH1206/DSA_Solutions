# [3651. Minimum Cost Path with Teleportations](https://leetcode.com/problems/minimum-cost-path-with-teleportations/)
**Difficulty:** `Hard` | **Tags:** `array`, `dynamic-programming`, `matrix`

---

## Problem Description
You are given a `m x n` 2D integer array `grid` and an integer `k`. You start at the top-left cell `(0, 0)` and your goal is to reach the bottom‐right cell `(m - 1, n - 1)`.

There are two types of moves available:

* **Normal move**: You can move right or down from your current cell `(i, j)`, i.e. you can move to `(i, j + 1)` (right) or `(i + 1, j)` (down). The cost is the value of the destination cell.
* **Teleportation**: You can teleport from any cell `(i, j)`, to any cell `(x, y)` such that `grid[x][y] <= grid[i][j]`; the cost of this move is 0. You may teleport at most `k` times.

Return the **minimum** total cost to reach cell `(m - 1, n - 1)` from `(0, 0)`.

**Example 1:**

**Input:** grid = [[1,3,3],[2,5,4],[4,3,5]], k = 2

**Output:** 7

**Explanation:**

Initially we are at (0, 0) and cost is 0.

| Current Position | Move | New Position | Total Cost |
| --- | --- | --- | --- |
| `(0, 0)` | Move Down | `(1, 0)` | `0 + 2 = 2` |
| `(1, 0)` | Move Right | `(1, 1)` | `2 + 5 = 7` |
| `(1, 1)` | Teleport to `(2, 2)` | `(2, 2)` | `7 + 0 = 7` |

The minimum cost to reach bottom-right cell is 7.

**Example 2:**

**Input:** grid = [[1,2],[2,3],[3,4]], k = 1

**Output:** 9

**Explanation:**

Initially we are at (0, 0) and cost is 0.

| Current Position | Move | New Position | Total Cost |
| --- | --- | --- | --- |
| `(0, 0)` | Move Down | `(1, 0)` | `0 + 2 = 2` |
| `(1, 0)` | Move Right | `(1, 1)` | `2 + 3 = 5` |
| `(1, 1)` | Move Down | `(2, 1)` | `5 + 4 = 9` |

The minimum cost to reach bottom-right cell is 9.

**Constraints:**

* `2 <= m, n <= 80`
* `m == grid.length`
* `n == grid[i].length`
* `0 <= grid[i][j] <= 104`
* `0 <= k <= 10`

---

## Solution & Editorial
# Intuition
The problem asks for the minimum cost to reach the bottom-right cell using two types of moves: standard grid traversal (right/down) and teleportation. Since teleportation allows jumping to any cell with a smaller or equal value, we can model this as a multi-stage dynamic programming problem where the state is defined by the number of teleportations used and the current grid position.

# Approach
1. Define `f[t][i][j]` as the minimum cost to reach cell `(i, j)` using exactly `t` teleportations.
2. Initialize `f` with infinity. Base case: `f[0][0][0] = 0`.
3. For `t = 0`, perform standard DP: `f[0][i][j] = min(f[0][i-1][j], f[0][i][j-1]) + grid[i][j]`.
4. For `t > 0`, the transition involves two phases:
   - **Teleportation Phase**: Pre-calculate the minimum cost to reach any cell `(x, y)` from any cell `(i, j)` where `grid[x][y] <= grid[i][j]`. We group cells by value and process them in descending order to maintain a running minimum `mn` of costs from previous teleportation counts.
   - **Normal Move Phase**: After potential teleportation, update the grid using standard right/down moves.
5. The final answer is the minimum of `f[t][m-1][n-1]` for all `0 <= t <= k`.

### Visual Trace (Example 1: k=2)
| State | (0,0) | (0,1) | (1,0) | (1,1) | (2,2) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| f[0] | 0 | 3 | 2 | 7 | 12 |
| f[1] | 0 | 0 | 0 | 0 | 0 |

# Complexity
- Time complexity: $$O(K \cdot M \cdot N)$$, where $$K$$ is the max teleportations, and $$M, N$$ are grid dimensions. We iterate through $$K$$ stages, and in each stage, we perform a grid traversal and a grouping sort/scan.
- Space complexity: $$O(K \cdot M \cdot N)$$ to store the DP table `f`.

# Code
```cpp
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int inf = INT_MAX / 2;

        vector<vector<vector<int>>> f(k + 1, vector<vector<int>>(m, vector<int>(n, inf)));

        f[0][0][0] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    f[0][i][j] = min(f[0][i][j], f[0][i - 1][j] + grid[i][j]);
                }
                if (j > 0) {
                    f[0][i][j] = min(f[0][i][j], f[0][i][j - 1] + grid[i][j]);
                }
            }
        }

        unordered_map<int, vector<pair<int, int>>> g;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = grid[i][j];
                g[x].push_back({i, j});
            }
        }

        vector<int> keys;
        keys.reserve(g.size());
        for (auto& e : g) {
            keys.push_back(e.first);
        }
        sort(keys.begin(), keys.end(), greater<int>());

        for (int t = 1; t <= k; t++) {
            int mn = inf;
            for (int key : keys) {
                auto& pos = g[key];
                for (auto& p : pos) {
                    mn = min(mn, f[t - 1][p.first][p.second]);
                }
                for (auto& p : pos) {
                    f[t][p.first][p.second] = mn;
                }
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i > 0) {
                        f[t][i][j] = min(f[t][i][j], f[t][i - 1][j] + grid[i][j]);
                    }
                    if (j > 0) {
                        f[t][i][j] = min(f[t][i][j], f[t][i][j - 1] + grid[i][j]);
                    }
                }
            }
        }

        int ans = inf;
        for (int t = 0; t <= k; t++) {
            ans = min(ans, f[t][m - 1][n - 1]);
        }
        return ans;
    }
};
```
