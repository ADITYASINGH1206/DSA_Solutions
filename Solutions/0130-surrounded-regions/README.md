# [130. Surrounded Regions](https://leetcode.com/problems/surrounded-regions/)
**Difficulty:** `Medium` | **Tags:** `array`, `depth-first-search`, `breadth-first-search`, `union-find`, `matrix`

---

## Problem Description
You are given an `m x n` matrix `board` containing **letters** `'X'` and `'O'`, **capture regions** that are **surrounded**:

* **Connect**: A cell is connected to adjacent cells horizontally or vertically.
* **Region**: To form a region **connect every** `'O'` cell.
* **Surround**: A region is surrounded if none of the `'O'` cells in that region are on the edge of the board. Such regions are **completely enclosed** by `'X'` cells.

To capture a **surrounded region**, replace all `'O'`s with `'X'`s **in-place** within the original board. You do not need to return anything.

**Example 1:**

**Input:** board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

**Output:** [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

**Explanation:**

In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

**Example 2:**

**Input:** board = [["X"]]

**Output:** [["X"]]

**Constraints:**

* `m == board.length`
* `n == board[i].length`
* `1 <= m, n <= 200`
* `board[i][j]` is `'X'` or `'O'`.

---

## Solution & Editorial
# Intuition
The problem asks us to capture all regions of `'O'` that are completely surrounded by `'X'`s. Any `'O'` that is connected to the boundary of the board (either directly or via a chain of adjacent `'O'`s) cannot be surrounded. Conversely, any `'O'` that has no path to the boundary is completely enclosed and must be flipped to `'X'`. Therefore, we can start a Depth-First Search (DFS) from all boundary cells containing `'O'`, mark all reachable `'O'`s as visited, and finally flip any unvisited `'O'` to `'X'`.

# Approach
1. Get the dimensions of the board: `n` as the number of rows and `m` as the number of columns. Initialize a 2D visited matrix `vis` of size `n x m` with zeros.
2. Iterate through the left and right boundary columns (`col = 0` and `col = m - 1`) for all rows. If an unvisited `'O'` is found, initiate `dfs` from that cell.
3. Iterate through the top and bottom boundary rows (`row = 0` and `row = n - 1`) for all columns. If an unvisited `'O'` is found, initiate `dfs` from that cell.
4. Inside the `dfs` function, mark the current cell as visited (`vis[row][col] = 1`). Explore all 4 cardinal directions (`drow` and `dcol`). If a neighbor is within bounds, contains `'O'`, and has not been visited, recursively call `dfs` on it.
5. After exploring from all boundary-connected `'O'` cells, iterate over the entire board. Any `'O'` cell where `vis[i][j]` is `0` is trapped and must be converted to `'X'`.

### Visual Trace (Example 1)
Initial Board:
```
X X X X
X O O X
X X O X
X O X X
```
- Boundary DFS marks boundary-connected `'O'` cells (none on boundaries in Example 1 except bottom-most `'O'` at `(3, 1)`).
- Board after DFS marks edge-connected components:
```
[v] [v] [v] [v]
[v] [ ] [ ] [v]
[v] [v] [ ] [v]
[v] [O] [v] [v]
```
- Unvisited internal `'O'` cells are flipped to `'X'`:
```
X X X X
X X X X
X X X X
X O X X
```

# Complexity
- Time complexity: $$O(M \times N)$$, where $$M$$ is the number of rows and $$N$$ is the number of columns. Each cell in the grid is visited at most once during the DFS traversal and once during the final scan.
- Space complexity: $$O(M \times N)$$ due to the auxiliary 2D visited matrix `vis` and the recursion stack depth in the worst-case scenario (e.g., a spiral of `'O'`s spanning the entire grid).

# Code
```cpp
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i = 0;i<n;i++){
            if(board[i][0] =='O' && !vis[i][0]){
                dfs(i,0,vis,board);
            }
            if(board[i][m-1] == 'O' && !vis[i][m-1]){
                dfs(i,m-1,vis,board);
            }
        }
        for(int i = 0;i<m;i++){
            if(board[0][i] =='O' && !vis[0][i]){
                dfs(0,i,vis,board);
            }
            if(board[n-1][i] == 'O' && !vis[n-1][i]){
                dfs(n-1,i,vis,board);
            }
        }

        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }


    }

    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& board){
        vis[row][col]=1;
        int n = board.size();
        int m = board[0].size();
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int i = 0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && !vis[nrow][ncol]){
                dfs(nrow,ncol,vis,board);
            }
        }
    }
};
```
