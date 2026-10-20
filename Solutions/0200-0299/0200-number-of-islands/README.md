# [200. Number of Islands](https://leetcode.com/problems/number-of-islands/)
**Difficulty:** `Medium` | **Tags:** `array`, `depth-first-search`, `breadth-first-search`, `union-find`, `matrix`

---

## Problem Description
Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return *the number of islands*.

An **island** is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

**Example 1:**

```
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
```

**Example 2:**

```
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 300`
* `grid[i][j]` is `'0'` or `'1'`.

---

## Solution & Editorial
# Intuition
The problem asks us to count the number of connected components of '1's (land) in a 2D binary grid, where connectivity is defined horizontally and vertically. We can traverse the grid cell by cell. Whenever we encounter an unvisited land cell ('1'), it signifies a new island. We initiate a Depth-First Search (DFS) from this cell to explore and mark all connected land cells as visited, preventing duplicate counts.

# Approach
1. Initialize dimensions $n = \text{grid.size()}$ and $m = \text{grid[0].size()}$. Create a 2D visited matrix `vis` of size $n \times m$ initialized to $0$, and an answer counter `ans = 0`.
2. Define direction arrays `drow = {-1, 0, 1, 0}` and `dcol = {0, 1, 0, -1}` to explore the 4-directional neighbors (up, right, down, left).
3. Iterate through every cell `(i, j)` in the grid using nested loops.
4. If `grid[i][j] == '1'` and `vis[i][j] == 0`, increment `ans` and call the recursive `dfs(i, j, vis, grid)` function.
5. Inside `dfs(row, col, vis, grid)`:
   - Mark the current cell as visited: `vis[row][col] = 1`.
   - Loop through the 4 possible directions to compute neighbor coordinates `nrow` and `ncol`.
   - If the neighbor is within bounds, is land (`'1'`), and has not been visited, recursively invoke `dfs` on `(nrow, ncol)`.
6. Return `ans` once all cells have been processed.

### Visual Walkthrough
Consider a small grid:
```
grid = [
  ["1", "1"],
  ["0", "0"]
]
```
- `i = 0, j = 0`: `grid[0][0] == '1'` and `vis[0][0] == 0`. `ans` becomes 1. `dfs(0, 0)` is called.
  - `vis[0][0] = 1`. Neighbors are checked. `grid[0][1]` is land and unvisited -> `dfs(0, 1)` is called.
  - `vis[0][1] = 1`. All neighbors processed. Returns.
- `i = 0, j = 1`: `vis[0][1] == 1`, skipped.
- `i = 1, j = 0`, `i = 1, j = 1`: `'0'`, skipped.
- Final `ans = 1`.

# Complexity
- Time complexity: $$O(N \times M)$$ — Every cell in the $N \times M$ grid is visited at most once during the nested loops and at most once during DFS traversal.
- Space complexity: $$O(N \times M)$$ — Due to the `vis` 2D vector and the recursion call stack in the worst-case scenario where the entire grid is land (depth up to $N \times M$).

# Code
```cpp
class Solution {
public:
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid){
        vis[row][col]=1;
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                dfs(nrow,ncol,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] =='1' && !vis[i][j]){
                    dfs(i,j,vis,grid);
                    ans++;
                }
            }
        }

        return ans;
    }

};
```
