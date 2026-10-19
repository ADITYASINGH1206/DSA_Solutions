# [695. Max Area of Island](https://leetcode.com/problems/max-area-of-island/)
**Difficulty:** `Medium` | **Tags:** `array`, `depth-first-search`, `breadth-first-search`, `union-find`, `matrix`

---

## Problem Description
You are given an `m x n` binary matrix `grid`. An island is a group of `1`'s (representing land) connected **4-directionally** (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The **area** of an island is the number of cells with a value `1` in the island.

Return *the maximum **area** of an island in* `grid`. If there is no island, return `0`.

**Example 1:**

```
Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
```

**Example 2:**

```
Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 50`
* `grid[i][j]` is either `0` or `1`.

---

## Solution & Editorial
# Intuition
The problem asks for the maximum area of a 4-directionally connected group of `1`s in a binary matrix. We can traverse the grid using Depth-First Search (DFS). Whenever we encounter an unvisited land cell (`1`), we initiate a DFS traversal to explore all connected land cells, accumulating the size of the island and updating the maximum area found so far.

# Approach
1. Initialize dimensions `m` and `n` of the `grid`, and a 2D boolean/integer visited array `vis` of size $$m \times n$$ initialized to `0`.
2. Define direction arrays `drow = {-1, 0, 1, 0}` and `dcol = {0, 1, 0, -1}` to iterate over the 4 orthogonal neighbors (up, right, down, left).
3. Iterate through every cell `(i, j)` in the grid using a nested loop.
4. If `grid[i][j] == 1` and `vis[i][j] == 0`, reset `area = 0` and trigger `dfs(...)`.
5. Inside `dfs(...)`, mark the current cell as visited (`vis[row][col] = 1`), increment `area`, and update `ans = max(ans, area)`.
6. For each of the 4 directions, compute the neighbor coordinates `nrow` and `ncol`. If the neighbor is within bounds, is unvisited land (`grid[nrow][ncol] == 1`), and not yet visited, recursively call `dfs(...)`.
7. Return the global maximum `ans` after scanning the entire grid.

### Complexity
- Time complexity: $$O(m \times n)$$ — Every cell in the grid is visited at most once during the nested loops and traversed at most once via DFS.
- Space complexity: $$O(m \times n)$$ — The visited matrix `vis` requires $$O(m \times n)$$ space, and the recursive call stack can grow up to $$O(m \times n)$$ in the worst-case scenario where the entire grid is a single island.

# Code
```cpp
class Solution {
public:
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};
    
    void dfs(vector<vector<int>>& grid, int& area, int& ans, vector<vector<int>>& vis, int row, int col, int& m, int& n){
        vis[row][col] = 1;

        area++;
        ans = max(ans, area);
        
        for(int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                dfs(grid, area, ans, vis, nrow, ncol, m, n);
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        
        int ans = 0;
        int area = 0; 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !vis[i][j]) {
                    area = 0; 
                    dfs(grid, area, ans, vis, i, j, m, n);
                }
            }
        }

        return ans;
    }
};
```
