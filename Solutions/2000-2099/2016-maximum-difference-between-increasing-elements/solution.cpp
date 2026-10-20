/**
 * Problem: Maximum Difference Between Increasing Elements (2016)
 * Link: https://leetcode.com/problems/maximum-difference-between-increasing-elements/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int mini = nums[0];
        for(int i =1;i<nums.size();i++){
            if(nums[i]>mini){
                ans=max(ans,nums[i]-mini);
            }else{
                mini=nums[i];
            }
        }
        return ans;
    }
};
