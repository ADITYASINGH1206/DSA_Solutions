/**
 * Problem: Unique Paths II (63)
 * Link: https://leetcode.com/problems/unique-paths-ii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

//Tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } 
                else if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } 
                else {
                    int up = 0, left = 0;
                    if (i > 0) up = dp[i-1][j];
                    if (j > 0) left = dp[i][j-1];
                    
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
//Memoization
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         vector<vector<int>> memo(m,vector<int>(n,-1));
//         return dp(m,n,0,0,memo,obstacleGrid);

//     }

//     int dp(int m,int n,int row,int col,vector<vector<int>>& memo,vector<vector<int>>& grid){
//         if(row == m-1 && col == n-1  && grid[row][col] == 0) return 1;

//         if(row >=m || col >= n || grid[row][col] == 1) return 0;

//         if(memo[row][col] != -1)return memo[row][col];
        
//         int down = dp(m,n,row+1,col,memo,grid);
//         int right = dp(m,n,row,col+1,memo,grid);

//         return memo[row][col] = down + right;
//     }
// };
