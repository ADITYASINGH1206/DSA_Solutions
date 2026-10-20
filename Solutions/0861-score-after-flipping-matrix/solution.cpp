/**
 * Problem: Score After Flipping Matrix (861)
 * Link: https://leetcode.com/problems/score-after-flipping-matrix/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < n; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        for(int col = 0; col < n; col++) {
            int zero = 0;
            for(int row = 0; row < m; row++) {
                if(grid[row][col] == 0) zero++;
            }
            if(zero > m / 2) {
                for(int row = 0; row < m; row++) {
                    grid[row][col] = 1 - grid[row][col];
                }
            }
        }
        for(int i = 0; i < m; i++) {
            int num = 0;
            for(int j = n - 1; j >= 0; j--) {
                if(grid[i][j] == 1) {
                    num += (1 << (n - 1 - j));
                }
            }
            ans += num;
        }
        return ans;
    }
};
