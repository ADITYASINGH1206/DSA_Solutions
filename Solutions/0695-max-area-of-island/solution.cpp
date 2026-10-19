/**
 * Problem: Max Area of Island (695)
 * Link: https://leetcode.com/problems/max-area-of-island/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

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
