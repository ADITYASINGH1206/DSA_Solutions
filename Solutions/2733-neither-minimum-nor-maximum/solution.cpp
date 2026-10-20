/**
 * Problem: Neither Minimum nor Maximum (2733)
 * Link: https://leetcode.com/problems/neither-minimum-nor-maximum/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n>2){
            ans = nums[1];
        }
        return ans;
    }
};
