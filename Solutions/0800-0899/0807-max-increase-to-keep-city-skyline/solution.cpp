/**
 * Problem: Max Increase to Keep City Skyline (807)
 * Link: https://leetcode.com/problems/max-increase-to-keep-city-skyline/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans =0;
        vector<vector<int>> newGrid(n,vector<int>(n));
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                int col_max =0,row_max =0;
                for(int x=0;x<n;x++){
                    col_max = max(col_max,grid[i][x]);
                }
                for(int y=0;y<n;y++){
                    row_max = max(row_max,grid[y][j]);
                }
                newGrid[i][j] = min(col_max,row_max);
            }
        }
        for(int i=0 ; i<n ;i++){
            for(int j=0;j<n;j++){
                ans+= newGrid[i][j]-grid[i][j];
            }
        }
        return ans;
    }
};
