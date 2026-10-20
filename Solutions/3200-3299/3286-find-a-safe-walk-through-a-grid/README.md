# [3286. Find a Safe Walk Through a Grid](https://leetcode.com/problems/find-a-safe-walk-through-a-grid/)
**Difficulty:** `Medium` | **Tags:** `array`, `breadth-first-search`, `graph`, `heap-priority-queue`, `matrix`, `shortest-path`

---

## Problem Description
You are given an `m x n` binary matrix `grid` and an integer `health`.

You start on the upper-left corner `(0, 0)` and would like to get to the lower-right corner `(m - 1, n - 1)`.

You can move up, down, left, or right from one cell to another adjacent cell as long as your health *remains* **positive**.

Cells `(i, j)` with `grid[i][j] = 1` are considered **unsafe** and reduce your health by 1.

Return `true` if you can reach the final cell with a health value of 1 or more, and `false` otherwise.

**Example 1:**

**Input:** grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1

**Output:** true

**Explanation:**

The final cell can be reached safely by walking along the gray cells below.

**Example 2:**

**Input:** grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]], health = 3

**Output:** false

**Explanation:**

A minimum of 4 health points is needed to reach the final cell safely.

**Example 3:**

**Input:** grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5

**Output:** true

**Explanation:**

The final cell can be reached safely by walking along the gray cells below.

Any path that does not go through the cell `(1, 1)` is unsafe since your health will drop to 0 when reaching the final cell.

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 50`
* `2 <= m * n`
* `1 <= health <= m + n`
* `grid[i][j]` is either 0 or 1.

---

## Solution & Editorial
# Intuition
The problem asks for a path from (0, 0) to (m-1, n-1) such that the total cost (sum of 1s encountered) is strictly less than the initial `health`. Since edge weights are only 0 or 1, this is a classic shortest path problem on a graph that can be solved efficiently using 0-1 BFS (Dijkstra's algorithm optimized for binary weights).

# Approach
1. Use a 2D array `dist` to store the minimum cost to reach each cell, initialized to `INT_MAX`.
2. Use a `deque` to perform 0-1 BFS. If moving to a cell with weight 0, push to the front; if weight 1, push to the back.
3. Start at (0, 0) with `dist[0][0] = grid[0][0]`.
4. For each neighbor, if the new path cost is smaller than the existing `dist`, update it and push to the `deque` accordingly.
5. Finally, check if `dist[m-1][n-1] < health`.

### Visual Trace (Example 1: grid 3x5, health 1)
| Step | Deque | Current | Neighbors Processed |
| :--- | :--- | :--- | :--- |
| 1 | {(0,0)} | (0,0) | (0,1), (1,0) |
| 2 | {(0,0), (1,0)} | (0,0) | (0,1) weight 1, (1,0) weight 0 |
| ... | ... | ... | ... |

# Complexity
- Time complexity: $$O(M \times N)$$ because each cell is added to and removed from the deque at most once.
- Space complexity: $$O(M \times N)$$ to store the `dist` matrix and the deque.

# Code
```cpp
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;

        dist[0][0] = grid[0][0];
        dq.push_front({0, 0});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            if (x == m - 1 && y == n - 1)
                return dist[x][y] < health;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                int w = grid[nx][ny];

                if (dist[x][y] + w < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + w;

                    if (w == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }

        return dist[m - 1][n - 1] < health;
    }
};
```
