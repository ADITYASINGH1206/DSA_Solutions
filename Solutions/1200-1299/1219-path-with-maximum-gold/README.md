# [1219. Path with Maximum Gold](https://leetcode.com/problems/path-with-maximum-gold/)
**Difficulty:** `Medium` | **Tags:** `array`, `backtracking`, `matrix`

---

## Problem Description
In a gold mine `grid` of size `m x n`, each cell in this mine has an integer representing the amount of gold in that cell, `0` if it is empty.

Return the maximum amount of gold you can collect under the conditions:

* Every time you are located in a cell you will collect all the gold in that cell.
* From your position, you can walk one step to the left, right, up, or down.
* You can't visit the same cell more than once.
* Never visit a cell with `0` gold.
* You can start and stop collecting gold from **any** position in the grid that has some gold.

**Example 1:**

```
Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.
```

**Example 2:**

```
Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 15`
* `0 <= grid[i][j] <= 100`
* There are at most **25** cells containing gold.

---

## Solution & Editorial
# Intuition
This problem asks us to find the maximum sum of gold we can collect by traversing adjacent non-zero cells in a grid, starting and stopping anywhere. Since we can choose any starting cell and visit each cell at most once without revisiting zeros, a Depth-First Search (DFS) with backtracking is the natural way to explore all valid paths.

# Approach
1. Iterate through every cell `(i, j)` in the grid. If `grid[i][j] > 0`, initiate a recursive backtracking function `backtrack` from this cell as a potential starting point.
2. Inside `backtrack`, add the current cell's gold to `sum` and update our global maximum `ans`.
3. Temporarily mark the current cell as visited by setting `grid[row][col] = 0` to prevent cycles during the current path traversal.
4. Explore all 4 orthogonal directions using direction arrays `drow` and `dcol`. If a neighbor `(nRow, nCol)` is within bounds and contains gold (`grid[nRow][nCol] > 0`), recursively call `backtrack`.
5. Backtrack by restoring the original gold value of `grid[row][col]` before returning, allowing other paths to reuse this cell.

### Visual Walkthrough (Example 1)
Grid:
[[0, 6, 0],
 [5, 8, 7],
 [0, 9, 0]]

Starting DFS at `(2, 1)` (value `9`):
- `sum` = 9, `ans` = 9, `grid[2][1]` temporarily set to 0.
- Move up to `(1, 1)` (value `8`):
  - `sum` = 9 + 8 = 17, `ans` = 17, `grid[1][1]` temporarily set to 0.
- From `(1, 1)`, move right to `(1, 2)` (value `7`):
  - `sum` = 17 + 7 = 24, `ans` = 24, `grid[1][2]` temporarily set to 0.
- No valid unvisited neighbors with gold from `(1, 2)`. Unwind recursion, restoring cell values.

# Complexity
- Time complexity: $$O(K \cdot 4^K)$$ where $$K$$ is the number of cells containing gold (at most 25). For each valid starting cell containing gold, the DFS explores paths branching up to 4 directions up to depth $$K$$.
- Space complexity: $$O(K)$$ for the recursion call stack during the deepest path traversal.

# Code
```cpp
class Solution {
public:
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};
    void backtrack(int& ans,vector<vector<int>>& grid,int sum,int row,int col,int m,int n){
        sum += grid[row][col];
        ans = max(ans,sum);
        int temp = grid[row][col];
        grid[row][col] = 0;
        for(int i =0;i<4;i++){
            int nRow = row+drow[i];
            int nCol = col+dcol[i];
            if(nRow>=0 && nCol >=0 && nRow <m && nCol <n && grid[nRow][nCol] >0){
                backtrack(ans,grid,sum,nRow,nCol,m,n);
            }
        }
        grid[row][col] = temp;
    
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans =0;
        for(int i = 0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0) backtrack(ans,grid,0,i,j,m,n);
            }
        }
        return ans;
    }
};
```
