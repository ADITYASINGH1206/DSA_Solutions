/**
 * Problem: Number of Islands (200)
 * Link: https://leetcode.com/problems/number-of-islands/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

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
