/**
 * Problem: Maximum Score of a Split (3788)
 * Link: https://leetcode.com/problems/maximum-score-of-a-split/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long ans = LLONG_MIN;
        vector<long long> prefix_sum;
        int n = nums.size();
        long long sum = 0;
        for(int i = 0;i<n-1;i++){
            sum += nums[i];
            prefix_sum.push_back(sum);
        }
        vector<int> suffix_min(n,0);
        int mini = INT_MAX;
        for(int i =n-1;i>0;i--){
            mini = min(mini,nums[i]);
            suffix_min[i-1] = mini;
        }
        for(int i = 0;i<n-1;i++){
            ans = max(ans,prefix_sum[i]-suffix_min[i]);
        }

        return ans;
    }
};
