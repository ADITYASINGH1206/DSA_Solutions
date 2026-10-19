/**
 * Problem: House Robber (198)
 * Link: https://leetcode.com/problems/house-robber/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int rob(vector<int>& nums){
        int n = nums.size();
        if(n == 0) return 0;

        int prev1= 0;
        int prev2= 0;

        for(int i=0;i<n;i++){
            int pick = nums[i] + prev2;
            int notPick = prev1;

            int current = max(pick,notPick);

            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }

};

// class Solution{
// public:
//     int rob(vector<int> & nums){
//         int n = nums.size();
//         vector<int> dp(n,-1);
//         dp[0] = nums[0];
//         for(int i = 1;i<n;i++){
//             int pick = nums[i];
//             if(i>1) pick+= dp[i-2];
//             int notPick = 0 + dp[i-1];
//             dp[i] = max(pick,notPick);
//         }
//         return dp[n-1];
//     }
// };


// class Solution {
// public:
//     int f(int ind,vector<int>& nums,vector<int>& dp){
//         if(ind == 0)return nums[ind];
//         if(ind < 0)return 0;

//         if(dp[ind] != -1) return dp[ind];

//         int pick = nums[ind] +f(ind-2,nums,dp);
//         int notPick = 0 + f(ind-1,nums,dp);

//         return dp[ind] = max(pick,notPick);

//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n,-1);
//         return f(n-1,nums,dp);
//     }
// };
