/**
 * Problem: Unique Paths III (980)
 * Link: https://leetcode.com/problems/unique-paths-iii/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>>& grid, int r, int c, int& row, int& clm,
                   int& ans,int& empty, int count) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() ||
            grid[r][c] == -1) {
            return;
        }

        if (grid[r][c] == 2) {
            if (count == empty)
                ans++;
            return;
        }

        int temp = grid[r][c];
        grid[r][c] = -1;

        backtrack(grid, r + 1, c, row, clm,ans,empty, count + 1);
        backtrack(grid, r - 1, c, row, clm,ans,empty, count + 1);
        backtrack(grid, r, c + 1, row, clm,ans,empty, count + 1);
        backtrack(grid, r, c - 1, row, clm,ans,empty, count + 1);
        grid[r][c] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int startR, startC;
        int ans = 0;
        int empty = 1;
        int row = grid.size();
        int clm = grid[0].size();

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    startR = i;
                    startC = j;
                } else if (grid[i][j] == 0) {
                    empty++;
                }
            }
        }

        backtrack(grid, startR, startC, row, clm,ans,empty,0);
        return ans;
    }
};
