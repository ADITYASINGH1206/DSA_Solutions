/**
 * Problem: Determine Whether Matrix Can Be Obtained By Rotation (1886)
 * Link: https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for (int k = 0; k < 4; ++k) {
            vector<vector<int>> g(n, vector<int>(n));
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    g[i][j] = mat[j][n - i - 1];
            if (g == target) return true;
            mat = g;
        }
        return false;
    }
};
