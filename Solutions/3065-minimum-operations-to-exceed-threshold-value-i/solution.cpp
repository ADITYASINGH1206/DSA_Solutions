/**
 * Problem: Minimum Operations to Exceed Threshold Value I (3065)
 * Link: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans =0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]<k){
                ans++;
            }
        }
        return ans;
    }
};
