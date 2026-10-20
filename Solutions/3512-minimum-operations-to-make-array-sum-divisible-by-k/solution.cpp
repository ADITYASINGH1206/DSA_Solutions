/**
 * Problem: Minimum Operations to Make Array Sum Divisible by K (3512)
 * Link: https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0,sum =0;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        return ans = sum % k;
    }
};
