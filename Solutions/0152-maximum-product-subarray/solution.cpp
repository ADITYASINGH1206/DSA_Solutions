/**
 * Problem: Maximum Product Subarray (152)
 * Link: https://leetcode.com/problems/maximum-product-subarray/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int ans = INT_MIN;
        int currentMax = 1;
        int currentMin = 1;
        for (int n : nums) {
            if (n < 0) {
                swap(currentMax, currentMin);
            }
            currentMax = max(n, currentMax * n);
            currentMin = min(n, currentMin * n);

            ans = max(ans, currentMax);
        }
        
        return ans;
    }
};
