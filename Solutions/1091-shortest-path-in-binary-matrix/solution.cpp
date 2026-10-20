/**
 * Problem: Shortest Path in Binary Matrix (1091)
 * Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(grid[0][0] == 1) return -1;
        q.push({{0,0},1});
        vis[0][0] = 1;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            int drow[] = {-1,-1,0,1,1,1,0,-1};
            int dcol[] = {0,1,1,1,0,-1,-1,-1};
            if(row == n-1 && col == n-1) return dis;
            for(int i =0;i<8;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && nrow<n && ncol >= 0 && ncol < n && !vis[nrow][ncol] && grid[nrow][ncol] == 0){
                    q.push({{nrow,ncol},dis+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return -1;

    }
};
