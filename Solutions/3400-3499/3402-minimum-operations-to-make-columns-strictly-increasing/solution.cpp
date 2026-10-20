/**
 * Problem: Minimum Operations to Make Columns Strictly Increasing (3402)
 * Link: https://leetcode.com/problems/minimum-operations-to-make-columns-strictly-increasing/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m ==1) return 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[j-1][i] >= grid[j][i]){
                    ans += grid[j-1][i]-grid[j][i]+1;
                    grid[j][i]= grid[j-1][i]+1;
                }
            }
        }
        return ans;
    }
};
