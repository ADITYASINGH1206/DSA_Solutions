/**
 * Problem: Flipping an Image (832)
 * Link: https://leetcode.com/problems/flipping-an-image/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void flipping(vector<vector<int>>& image){
        int n = image.size();
        for(int i = 0;i<n;i++){
            reverse(image[i].begin(),image[i].end());
        }
    }
    void invert(vector<vector<int>> & image){
        int n = image.size();
        for(int i = 0 ;i<n;i++){
            for(int j =0;j<n;j++){
                if(image[i][j]) image[i][j] = 0;
                else image[i][j] = 1;
            }
        }
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        flipping(image);
        invert(image);
        return image;
    }
};
