/**
 * Problem: Sort Matrix by Diagonals (3446)
 * Link: https://leetcode.com/problems/sort-matrix-by-diagonals/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1) return grid;
        
        int srow = n - 1, scol = 0;
        int k = 0;
        while(k < n){
            vector<int> elements;
            int row = srow, col = scol;
            int erow = n, ecol = n; 
            while(row < erow && col < ecol){
                elements.push_back(grid[row][col]);
                row++, col++;
            }
            sort(elements.rbegin(), elements.rend());
            
            int l = 0;
            row = srow, col = scol;
            while(row < erow && col < ecol){
                grid[row][col] = elements[l];
                l++, row++, col++;
            }
            
            k++;
            srow--; 
        }
        k = 0;
        srow=0,scol =n-1;
        while(k<n-1){
            vector<int> elements;
            int row = srow, col = scol;
            int erow = n, ecol = n; 
            while(row < erow && col < ecol){
                elements.push_back(grid[row][col]);
                row++, col++;
            }
            sort(elements.begin(), elements.end());
            
            int l = 0;
            row = srow, col = scol;
            while(row < erow && col < ecol){
                grid[row][col] = elements[l];
                l++, row++, col++;
            }
            
            k++;
            scol--; 
        }
        
        return grid;
    }
};
