/**
 * Problem: Cyclically Shift Rows and Columns (4052)
 * Link: https://leetcode.com/problems/cyclically-shift-rows-and-columns/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>> tempGrid(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                tempGrid[i][j] = grid[i][(j + rowShift[i]) % n];
            }
        }
        
        vector<vector<int>> ans(n, vector<int>(n));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = tempGrid[(i + colShift[j]) % n][j];
            }
        }
        
        return ans;
    }
};
