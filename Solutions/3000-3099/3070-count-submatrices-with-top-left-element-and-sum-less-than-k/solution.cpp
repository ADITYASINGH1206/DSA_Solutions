/**
 * Problem: Count Submatrices with Top-Left Element and Sum Less Than k (3070)
 * Link: https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int s[m + 1][n + 1];
        memset(s, 0, sizeof(s));
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1];
                if (s[i][j] <= k) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
