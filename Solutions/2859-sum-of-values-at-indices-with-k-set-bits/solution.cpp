/**
 * Problem: Sum of Values at Indices With K Set Bits (2859)
 * Link: https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (__builtin_popcount(i) == k) {
                ans += nums[i];
            }
        }
        return ans;
    }
};
