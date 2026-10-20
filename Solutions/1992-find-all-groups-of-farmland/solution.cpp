/**
 * Problem: Find All Groups of Farmland (1992)
 * Link: https://leetcode.com/problems/find-all-groups-of-farmland/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int drow[2] = {0,1};
    int dcol[2] = {1,0};
    void dfs(vector<vector<int>>& land,vector<vector<int>>& vis,vector<int>& ans,int row,int col,int&m ,int&n){
        vis[row][col] = 1;
        ans[0] = max(ans[0],row);
        ans[1] = max(ans[1],col);
        for(int i=0;i<2;i++){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            if(nrow >=0 && ncol >=0 && nrow<m && ncol <n && !vis[nrow][ncol] && land[nrow][ncol] == 1){
                dfs(land,vis,ans,nrow,ncol,m,n);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                if(land[i][j] == 1 && !vis[i][j]){
                    vector<int> end(2,0);
                    vector<int> temp(4,0);
                    dfs(land,vis,end,i,j,m,n);
                    temp[0]= i , temp[1] = j;
                    temp[2] = end[0] , temp[3] = end[1];
                    ans.push_back(temp);
                }
            }
        }
        return ans;

    }
};
