/**
 * Problem: Path with Maximum Gold (1219)
 * Link: https://leetcode.com/problems/path-with-maximum-gold/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};
    void backtrack(int& ans,vector<vector<int>>& grid,int sum,int row,int col,int m,int n){
        sum += grid[row][col];
        ans = max(ans,sum);
        int temp = grid[row][col];
        grid[row][col] = 0;
        for(int i =0;i<4;i++){
            int nRow = row+drow[i];
            int nCol = col+dcol[i];
            if(nRow>=0 && nCol >=0 && nRow <m && nCol <n && grid[nRow][nCol] >0){
                backtrack(ans,grid,sum,nRow,nCol,m,n);
            }
        }
        grid[row][col] = temp;
    
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans =0;
        for(int i = 0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0) backtrack(ans,grid,0,i,j,m,n);
            }
        }
        return ans;
    }
};
