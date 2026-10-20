/**
 * Problem: Rearrange Array to Maximize Prefix Score (2587)
 * Link: https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        
        long long sum = 0;
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            if (sum > 0) {
                ans++;
            } else {
                break;
            }
        }
        
        return ans;
    }
};
