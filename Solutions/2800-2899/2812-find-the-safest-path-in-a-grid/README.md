# [2812. Find the Safest Path in a Grid](https://leetcode.com/problems/find-the-safest-path-in-a-grid/)
**Difficulty:** `Medium` | **Tags:** `array`, `binary-search`, `breadth-first-search`, `union-find`, `heap-priority-queue`, `matrix`

---

## Problem Description
You are given a **0-indexed** 2D matrix `grid` of size `n x n`, where `(r, c)` represents:

* A cell containing a thief if `grid[r][c] = 1`
* An empty cell if `grid[r][c] = 0`

You are initially positioned at cell `(0, 0)`. In one move, you can move to any adjacent cell in the grid, including cells containing thieves.

The **safeness factor** of a path on the grid is defined as the **minimum** manhattan distance from any cell in the path to any thief in the grid.

Return *the **maximum safeness factor** of all paths leading to cell* `(n - 1, n - 1)`*.*

An **adjacent** cell of cell `(r, c)`, is one of the cells `(r, c + 1)`, `(r, c - 1)`, `(r + 1, c)` and `(r - 1, c)` if it exists.

The **Manhattan distance** between two cells `(a, b)` and `(x, y)` is equal to `|a - x| + |b - y|`, where `|val|` denotes the absolute value of val.

**Example 1:**

```
Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
Output: 0
Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).
```

**Example 2:**

```
Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 2) is cell (0, 0). The distance between them is | 0 - 0 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.
```

**Example 3:**

```
Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 3) is cell (1, 2). The distance between them is | 0 - 1 | + | 3 - 2 | = 2.
- The closest cell of the path to the thief at cell (3, 0) is cell (3, 2). The distance between them is | 3 - 3 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.
```

**Constraints:**

* `1 <= grid.length == n <= 400`
* `grid[i].length == n`
* `grid[i][j]` is either `0` or `1`.
* There is at least one thief in the `grid`.

---

## Solution & Editorial
# Intuition
To maximize the minimum distance to any thief along a path, we first need to know the distance from every cell to its nearest thief. This is a classic multi-source BFS problem. Once we have these distances, the problem transforms into finding a path from (0, 0) to (n-1, n-1) that maximizes the minimum value of the cells visited, which is effectively a variation of Dijkstra's algorithm.

# Approach
1. **Multi-Source BFS**: Initialize a queue with all cells containing thieves (`grid[r][c] == 1`). Perform a BFS to compute the Manhattan distance from every cell to the nearest thief, storing these in a `dist` matrix.
2. **Modified Dijkstra**: Use a max-priority queue to explore paths. The priority queue stores `{safeness_factor, {r, c}}`, where `safeness_factor` is the minimum distance encountered so far on the path. We always expand the path with the highest current safeness factor.
3. **Termination**: The first time we extract `(n-1, n-1)` from the priority queue, the associated `safeness_factor` is guaranteed to be the maximum possible.

### Visual Trace (Example 2)
`grid = [[0,0,1],[0,0,0],[0,0,0]]`
- **BFS Step**: Distances to nearest thief (0, 2):
  `[[2, 1, 0], [3, 2, 1], [4, 3, 2]]`
- **Dijkstra Step**:
  - Start at (0,0) with `dist=2`. PQ: `{(2, 0, 0)}`
  - Pop (0,0), explore neighbors (0,1) and (1,0). PQ: `{(1, 0, 1), (1, 1, 0)}`
  - Continue until (2,2) is reached with `min(2, 1, 2, 2) = 2`.

# Complexity
- Time complexity: $$O(N^2 \log N)$$. The multi-source BFS visits each cell once ($$O(N^2)$$). The priority queue operations in the Dijkstra phase process each cell at most once, with each insertion/extraction taking $$O(\log N^2) = O(\log N)$$.
- Space complexity: $$O(N^2)$$. We maintain a `dist` matrix, a `vis` matrix, and a priority queue, all of which scale with the number of cells in the grid.

# Code
```cpp
class Solution {
public:
    int n;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(n, 0));
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(grid[r][c] == 1){
                    vis[r][c] = true;
                    q.push({r, c});
                }
            }
        }
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int d = 0; d < 4; d++){
                int nr = r + dx[d];
                int nc = c + dy[d];

                if(nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
                if(vis[nr][nc]) continue;

                dist[nr][nc] = dist[r][c] + 1;
                vis[nr][nc] = true;
                q.push({nr, nc});
            }
        }
        priority_queue<pair<int, pair<int,int>>> store;
        vector<vector<bool>> vis2(n, vector<bool>(n, false));

        store.push({dist[0][0], {0, 0}});

        while(!store.empty()){
            auto pr = store.top();
            store.pop();

            int safeE = pr.first;
            int r = pr.second.first;
            int c = pr.second.second;

            if(vis2[r][c]) continue;
            vis2[r][c] = true;
            if(r == n - 1 && c == n - 1) return safeE;

            for(int d = 0; d < 4; d++){
                int nr = r + dx[d];
                int nc = c + dy[d];

                if(nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
                if(vis2[nr][nc]) continue;

                int newSafe = min(safeE, dist[nr][nc]);
                store.push({newSafe, {nr, nc}});
            }
        }

        return 0;
    }
};
```
