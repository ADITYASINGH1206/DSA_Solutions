/**
 * Problem: Maximum Consistent Columns in a Grid (3989)
 * Link: https://leetcode.com/problems/maximum-consistent-columns-in-a-grid/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, 1);
        int ans = 1;
        
        for (int j = 1; j < n; ++j) {
            for (int k = 0; k < j; ++k) {
                bool check = true;
                for (int i = 0; i < m; ++i) {
                    if (abs(grid[i][j] - grid[i][k]) > limit) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    dp[j] = max(dp[j], dp[k] + 1);
                }
            }
            ans = max(ans, dp[j]);
        }
        
        return ans;
    }
};
