/**
 * Problem: Minimize Maximum Pair Sum in Array (1877)
 * Link: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l < r){
            ans = max(ans,nums[l++]+nums[r--]);
        }
        return ans;
    }
};
