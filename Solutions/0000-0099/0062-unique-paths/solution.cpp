/**
 * Problem: Unique Paths (62)
 * Link: https://leetcode.com/problems/unique-paths/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int&m,int& n,int row,int col,vector<vector<int>>& grid){
        if(row == m-1 && col == n-1) return 1;

        if(row >= m || col >= n) return 0;
        if(grid[row][col] != -1) return grid[row][col];

        int down = dfs(m,n,row+1,col,grid);
        int right = dfs(m,n,row,col+1,grid);

        return grid[row][col] = down + right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m,vector<int>(n,-1));
        return dfs(m,n,0,0,grid);

    }
};
