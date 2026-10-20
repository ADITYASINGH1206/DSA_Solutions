/**
 * Problem: Flip Square Submatrix Vertically (3643)
 * Link: https://leetcode.com/problems/flip-square-submatrix-vertically/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = x; i < x + k / 2; i++) {
            int i2 = x + k - 1 - (i - x);
            for (int j = y; j < y + k; j++) {
                swap(grid[i][j], grid[i2][j]);
            }
        }
        return grid;
    }
};
