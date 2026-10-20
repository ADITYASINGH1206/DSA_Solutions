# [1020. Number of Enclaves](https://leetcode.com/problems/number-of-enclaves/)
**Difficulty:** `Medium` | **Tags:** `array`, `depth-first-search`, `breadth-first-search`, `union-find`, `matrix`

---

## Problem Description
You are given an `m x n` binary matrix `grid`, where `0` represents a sea cell and `1` represents a land cell.

A **move** consists of walking from one land cell to another adjacent (**4-directionally**) land cell or walking off the boundary of the `grid`.

Return *the number of land cells in* `grid` *for which we cannot walk off the boundary of the grid in any number of **moves***.

**Example 1:**

```
Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
```

**Example 2:**

```
Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 500`
* `grid[i][j]` is either `0` or `1`.

---

## Solution & Editorial
# Intuition
Any land cell connected to the boundary of the grid can walk off the boundary. Conversely, any land cell that cannot reach the boundary is an enclave. Therefore, we can start a Depth-First Search (DFS) from all boundary land cells to mark every reachable land cell, and then count all remaining unvisited land cells.

# Approach
1. Initialize dimensions `n` and `m`, and a visited matrix `vis` of size `n x m` filled with zeros.
2. Iterate over all boundary rows (left column `0` and right column `m - 1`) and boundary columns (top row `0` and bottom row `n - 1`). If a cell contains land (`1`) and is unvisited, invoke `dfs` to traverse and mark all connected land cells.
3. Traverse the entire grid after DFS. Any cell that remains land (`1`) and is unvisited represents an enclave. Increment `ans` for each such cell.
4. Return `ans`.

### Visual Walkthrough (Example 1)
Grid:
```
0 0 0 0
1 0 1 0
0 1 1 0
0 0 0 0
```
- Boundary DFS marks boundary land at `(1, 0)`. Its connected components are checked, but it has no adjacent land.
- After visiting, we scan the inner grid:
  - `(1, 2)` is land and unvisited -> `ans = 1`
  - `(2, 1)` is land and unvisited -> `ans = 2`
  - `(2, 2)` is land and unvisited -> `ans = 3`
- Total enclaves = 3.

# Complexity
- Time complexity: $$O(M \times N)$$ — Each cell in the `m x n` grid is visited at most once during the boundary traversal and the final counting scan.
- Space complexity: $$O(M \times N)$$ — The visited matrix `vis` and the DFS recursion stack take up to $$O(M \times N)$$ space in the worst case of a fully connected grid.

# Code
```cpp
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !vis[i][0]) {
                dfs(i, 0, vis, grid);
            }
            if (grid[i][m - 1] == 1 && !vis[i][m - 1]) {
                dfs(i, m - 1, vis, grid);
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1 && !vis[0][i]) {
                dfs(0, i, vis, grid);
            }
            if (grid[n - 1][i] == 1 && !vis[n - 1][i]) {
                dfs(n - 1, i, vis, grid);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    ans++;
                }
            }
        }
        return ans;
    }

    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<int>>& grid) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                dfs(nrow, ncol, vis, grid);
            }
        }
    }
};
```
