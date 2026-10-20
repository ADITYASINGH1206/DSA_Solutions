/**
 * Problem: Subarray Sum Equals K (560)
 * Link: https://leetcode.com/problems/subarray-sum-equals-k/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mpp;
        mpp[0] =1;
        int ans=0;
        int presum =0;
        for(int i=0;i<nums.size();i++){
            presum+= nums[i];
            int remove = presum-k;
            ans += mpp[remove];
            mpp[presum] += 1;

        }
        return ans;
    }
};
