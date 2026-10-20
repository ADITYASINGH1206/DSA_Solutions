/**
 * Problem: Maximum Total Subarray Value I (3689)
 * Link: https://leetcode.com/problems/maximum-total-subarray-value-i/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        auto [mini, maxi] = minmax_element(nums.begin(), nums.end());
        return 1LL * k * (*maxi - *mini);
    }
};
