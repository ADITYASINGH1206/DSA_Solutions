/**
 * Problem: Triangle (120)
 * Link: https://leetcode.com/problems/triangle/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

//Tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n - 1];
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
            }
        }
        return dp[0];
    }
};

//DP
// class Solution {
// public:
//     int dp(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& memo) {
//         if (row == triangle.size() - 1) {
//             return triangle[row][col];
//         }

//         if (memo[row][col] != -1) {
//             return memo[row][col];
//         }
//         int down = dp(row + 1, col, triangle, memo);
//         int downRight = dp(row + 1, col + 1, triangle, memo);

//         return memo[row][col] = triangle[row][col] + min(down, downRight);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m = triangle.size();
//         vector<vector<int>> memo(m,vector<int>(m,-1));
//         return dp(0,0,triangle,memo);
//     }
// };
