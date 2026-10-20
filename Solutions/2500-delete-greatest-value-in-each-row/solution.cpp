/**
 * Problem: Delete Greatest Value in Each Row (2500)
 * Link: https://leetcode.com/problems/delete-greatest-value-in-each-row/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        if(m==n && m ==1) return grid[0][0];
        for(int i = 0;i<m;i++){
            sort(grid[i].begin(),grid[i].end());
        }
        for(int i =0;i<n;i++){
            int temp = INT_MIN;
            for(int j=0;j<m;j++){
                if(grid[j][i] > temp) temp = grid[j][i];
            }
            ans += temp;
        }
        return ans;
    }
};
