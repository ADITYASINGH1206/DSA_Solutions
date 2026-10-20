/**
 * Problem: Maximum Subarray (53)
 * Link: https://leetcode.com/problems/maximum-subarray/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum =0;
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+= nums[i];
            if(sum > ans){
                ans = sum;
            }
            if(sum<0){
                sum =0;
            }
        }
        return ans;
    }
};
