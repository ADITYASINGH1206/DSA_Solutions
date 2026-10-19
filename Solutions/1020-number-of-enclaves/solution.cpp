/**
 * Problem: Number of Enclaves (1020)
 * Link: https://leetcode.com/problems/number-of-enclaves/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !vis[i][0]) {
                dfs(i, 0, vis, grid);
            }
            if (grid[i][m - 1] == 1 && !vis[i][m - 1]) {
                dfs(i, m - 1, vis, grid);
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1 && !vis[0][i]) {
                dfs(0, i, vis, grid);
            }
            if (grid[n - 1][i] == 1 && !vis[n - 1][i]) {
                dfs(n - 1, i, vis, grid);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    ans++;
                }
            }
        }
        return ans;
    }

    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<int>>& grid) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                dfs(nrow, ncol, vis, grid);
            }
        }
    }
};
