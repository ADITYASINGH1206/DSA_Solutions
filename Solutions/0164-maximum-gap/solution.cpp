/**
 * Problem: Maximum Gap (164)
 * Link: https://leetcode.com/problems/maximum-gap/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff = 0;
        if(n < 2){
            return 0;
        }
        int i = 0;
        while(i < n-1){
            diff = max(diff, nums[i+1] - nums[i]);
            i++;
        }
        return diff;    
    }
};
