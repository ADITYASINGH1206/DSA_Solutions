/**
 * Problem: Final Array State After K Multiplication Operations I (3264)
 * Link: https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minres(vector<int>& nums){
        int idx = 0;
        int mn = INT_MAX;
        for(int i =0;i<nums.size();i++){
            if(nums[i] < mn){
                mn = nums[i];
                idx = i;
            }
        }
        return idx;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        for(int i=0;i<k;i++){
            nums[minres(nums)] = multiplier* nums[minres(nums)];
        }
        return nums;
    }
};
