/**
 * Problem: Create Grid With Exactly One Path (3963)
 * Link: https://leetcode.com/problems/create-grid-with-exactly-one-path/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));
        
        int r = 0, c = 0;
        grid[r][c] = '.'; 
        bool moveRight = true;
        
        while (r < m - 1 || c < n - 1) {
            if (moveRight) {
                if (c < n - 1) {
                    c++;
                } else {
                    r++;
                }
            } else {
                if (r < m - 1) {
                    r++;
                } else {
                    c++;
                }
            }
            grid[r][c] = '.';
            moveRight = !moveRight;
        }
        
        return grid;
    }
};
