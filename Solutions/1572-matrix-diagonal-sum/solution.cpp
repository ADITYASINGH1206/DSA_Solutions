/**
 * Problem: Matrix Diagonal Sum (1572)
 * Link: https://leetcode.com/problems/matrix-diagonal-sum/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m = mat.size();
        int ans = 0;
        for(int i = 0;i<m;i++){
            ans += mat[i][i];
            ans += mat[i][m-i-1];
        }
        if(m%2){
            int mid = m/2;
            ans -= mat[mid][mid];
        }
        return ans;
    }
};
