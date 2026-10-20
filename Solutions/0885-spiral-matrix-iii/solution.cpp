/**
 * Problem: Spiral Matrix III (885)
 * Link: https://leetcode.com/problems/spiral-matrix-iii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int total = rows*cols;
        ans.push_back({rStart,cStart});
        int row = rStart , col = cStart;
        int k = 0;
        int r = 1, d = 1, l =2, u = 2;
        while(ans.size()<total){
            //Right
            for(int i = 0;i<r;i++){
                col++;
                if(row<rows && col<cols && row>=0 && col>=0){
                    ans.push_back({row,col});
                }
            }
            r+=2;

            //Down
            for(int i = 0;i<d;i++){
                row++;
                if(row<rows && col<cols && row>=0 && col>=0){
                    ans.push_back({row,col});
                }
            }
            d+=2;

            //Left
            for(int i = 0;i<l;i++){
                col--;
                if(row<rows && col<cols && row>=0 && col>=0){
                    ans.push_back({row,col});
                }
            }
            l+=2;

            //Up
            for(int i = 0;i<u;i++){
                row--;
                if(row<rows && col<cols && row>=0 && col>=0){
                    ans.push_back({row,col});
                }
            }
            u+=2;
        }


        return ans;
    }
};
