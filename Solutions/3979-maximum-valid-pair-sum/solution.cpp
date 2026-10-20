/**
 * Problem: Maximum Valid Pair Sum (3979)
 * Link: https://leetcode.com/problems/maximum-valid-pair-sum/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= k) return 0; 
        
        int ans = 0; 
        int max_left = nums[0]; 

        for (int r = k; r < n; r++) {
            max_left = max(max_left, nums[r - k]);
            ans = max(ans, max_left + nums[r]);
        }

        return ans;
    }
};
