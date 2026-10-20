/**
 * Problem: Sum of Variable Length Subarrays (3427)
 * Link: https://leetcode.com/problems/sum-of-variable-length-subarrays/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int start = max(0, i - nums[i]);
            for (int j = start; j <= i; ++j) {
                ans += nums[j];
            }
        }
        return ans;
    }
};
