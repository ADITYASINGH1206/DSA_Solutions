/**
 * Problem: Cells with Odd Values in a Matrix (1252)
 * Link: https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int ans = 0;
        vector<vector<int>> mat(m,vector<int>(n,0));
        int x = indices.size();
        unordered_map<int,int> row;
        unordered_map<int,int> cols;
        for(int i =0;i<x;i++){
            row[indices[i][0]]++;
        }
        for(int i =0;i<x;i++){
            cols[indices[i][1]]++;
        }
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                if(row[i]) mat[i][j] += row[i];
                if(cols[j]) mat[i][j] += cols[j];
            }
        }
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                if(mat[i][j]%2 != 0) ans++;
            }
        }
        return ans;

    }
};
