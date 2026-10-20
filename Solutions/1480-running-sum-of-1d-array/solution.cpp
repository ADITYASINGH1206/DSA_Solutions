/**
 * Problem: Running Sum of 1d Array (1480)
 * Link: https://leetcode.com/problems/running-sum-of-1d-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>res(nums.size());
        int ans =0;
        for(int i =0 ; i<nums.size() ; i++){
            ans+= nums[i];
            res[i]=ans;
            
        }
        return res;
    }
};
