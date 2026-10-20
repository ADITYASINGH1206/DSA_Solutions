/**
 * Problem: Find Indices of Stable Mountains (3285)
 * Link: https://leetcode.com/problems/find-indices-of-stable-mountains/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> ans;
        for(int i=1;i<height.size();i++){
            if(height[i-1]>threshold){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
