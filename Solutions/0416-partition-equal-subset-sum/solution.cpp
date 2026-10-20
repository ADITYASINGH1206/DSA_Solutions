/**
 * Problem: Partition Equal Subset Sum (416)
 * Link: https://leetcode.com/problems/partition-equal-subset-sum/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

//Tabulation
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2 == 1) return false;
        int target = sum/2;
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        for(int i =0;i<n;i++) dp[i][0] = true;
        if(nums[0] <= target) dp[0][nums[0]] = true;
        for(int i =1;i<n;i++){
            for(int j =1;j<=target;j++){
                bool notTake = dp[i-1][j];
                bool take = false;
                if(nums[i]<=j) take = dp[i-1][j-nums[i]];
                dp[i][j]=take | notTake;
            }
        }
        return dp[n-1][target];
    }
};

//MEMO
// class Solution {
// public:
//     bool subsetSum(int ind,int target,vector<int> nums,vector<vector<int>>& dp){
//         if(target == 0) return true;
//         if(ind ==0 ) return nums[ind] == target;

//         if(dp[ind][target] != -1) return dp[ind][target];

//         bool notTake = subsetSum(ind-1,target,nums,dp);
//         bool take = false;
//         if(nums[ind] <= target) take = subsetSum(ind-1,target-nums[ind],nums,dp);

//         return dp[ind][target] = take | notTake;
//     }
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int sum = accumulate(nums.begin(),nums.end(),0);
//         if(sum%2 !=0 )return false;
//         int target = sum/2;
//         vector<vector<int>> dp(n,vector<int>(target+1,-1));
//         return subsetSum(n-1,target,nums,dp);
//     }
// };
