/**
 * Problem: Minimum Path Sum (64)
 * Link: https://leetcode.com/problems/minimum-path-sum/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

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
