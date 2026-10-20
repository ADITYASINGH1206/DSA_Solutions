/**
 * Problem: Minimum Operations to Make Array Non Decreasing (3914)
 * Link: https://leetcode.com/problems/minimum-operations-to-make-array-non-decreasing/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(std::vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n-1; i++) {
            if (nums[i] > nums[i + 1]) {
                ans += (nums[i] - nums[i + 1]);
            }
        }
        
        return ans;
    }
};
