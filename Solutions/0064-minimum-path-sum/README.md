# [64. Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/)
**Difficulty:** `Medium` | **Tags:** `array`, `dynamic-programming`, `matrix`

---

## Problem Description
Given a `m x n` `grid` filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

**Note:** You can only move either down or right at any point in time.

**Example 1:**

```
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
```

**Example 2:**

```
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 200`
* `0 <= grid[i][j] <= 200`

---

## Solution & Editorial
# Intuition
The problem asks us to find a path from the top-left cell `(0, 0)` to the bottom-right cell `(m-1, n-1)` that minimizes the sum of numbers along the path, given that we can only move down or right. Since the optimal path to any cell depends only on the optimal paths to its top and left neighbors, we can use dynamic programming (tabulation) to build up the solution efficiently.

# Approach
1. Extract dimensions `m` (rows) and `n` (cols) from the `grid`. Initialize a 2D DP table `dp` of size `m x n` with zeros.
2. Iterate through each cell `(r, c)` using nested loops from top to bottom, left to right.
3. At the starting cell `(0, 0)`, set `dp[0][0] = grid[0][0]`.
4. For cells in the first row (`r == 0`, `c > 0`), the only way to reach them is from the left. Thus, `dp[r][c] = dp[r][c-1] + grid[r][c]`.
5. For cells in the first column (`c == 0`, `r > 0`), the only way to reach them is from above. Thus, `dp[r][c] = dp[r-1][c] + grid[r][c]`.
6. For any other cell `(r, c)`, take the minimum of coming from above (`dp[r-1][c]`) or coming from the left (`dp[r][c-1]`), and add the current cell value `grid[r][c]`.
7. Return the final value stored at `dp[m-1][n-1]`.

### Visual Trace Walkthrough (Example 1)
Grid: `[[1, 3, 1], [1, 5, 1], [4, 2, 1]]`

| r \ c | c = 0 | c = 1 | c = 2 |
|---|---|---|---|
| **r = 0** | 1 | 1+3 = 4 | 4+1 = 5 |
| **r = 1** | 1+1 = 2 | min(4,2)+5 = 7 | min(7,5)+1 = 6 |
| **r = 2** | 2+4 = 6 | min(6,7)+2 = 8 | min(8,6)+1 = 7 |

Final output at `dp[2][2]` is `7`.

# Complexity
- Time complexity: $$O(m \times n)$$ — We visit each cell in the `m x n` grid exactly once and perform constant-time operations.
- Space complexity: $$O(m \times n)$$ — Auxiliary space required for the 2D `dp` table of size `m x n`.

# Code
```cpp
//Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (r == 0 && c == 0) {
                    dp[r][c] = grid[r][c];
                } else if (r == 0) {
                    dp[r][c] = dp[r][c-1] + grid[r][c];
                } else if (c == 0) {
                    dp[r][c] = dp[r-1][c] + grid[r][c];
                }
                else {
                    dp[r][c] = grid[r][c] + min(dp[r-1][c], dp[r][c-1]);
                }
            }
        }

        return dp[m-1][n-1];
    }
};


//DP
// class Solution {
// public:
//     int dp(int m,int n,int row,int col,vector<vector<int>>& memo,vector<vector<int>>& grid){
//         if (row >= m || col >= n) return 1e9;
//         if (row == m - 1 && col == n - 1) return grid[row][col];
//         if (memo[row][col] != -1) return memo[row][col];

//         int down = dp(m, n, row + 1, col, memo, grid);
//         int right = dp(m, n, row, col + 1, memo, grid);

//         return memo[row][col] = grid[row][col] + min(down, right);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> memo(m,vector<int>(n,-1));

//         return dp(m,n,0,0,memo,grid);
//     }
// };
```
