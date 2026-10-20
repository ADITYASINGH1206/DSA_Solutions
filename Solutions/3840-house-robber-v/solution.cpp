/**
 * Problem: House Robber V (3840)
 * Link: https://leetcode.com/problems/house-robber-v/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        long long ans = nums[0];  
        long long prev = 0;       
        int cls = colors[0];
        int n = nums.size();
        
        for(int i = 1; i < n; i++) {
            if(colors[i] == cls) {
                long long temp = ans;
                ans = max(ans, prev + nums[i]);
                prev = temp; 
            }
            else {
                prev = ans; 
                ans += nums[i];
                cls = colors[i];
            }
        }
        return ans;
    }
};
