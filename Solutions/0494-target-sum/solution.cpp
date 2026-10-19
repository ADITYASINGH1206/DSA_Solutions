/**
 * Problem: Target Sum (494)
 * Link: https://leetcode.com/problems/target-sum/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>&nums,int target,int ind,int sum,int& ans){
        int n = nums.size();
        if(ind == n){
            if(sum == target) ans++;
            return;
        }

        backtrack(nums,target,ind+1,sum+nums[ind],ans);
        backtrack(nums,target,ind+1,sum-nums[ind],ans);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        backtrack(nums,target,0,0,ans);
        return ans;
    }
};
