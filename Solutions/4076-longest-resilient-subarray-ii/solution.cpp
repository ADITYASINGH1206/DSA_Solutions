/**
 * Problem: Longest Resilient Subarray II (4076)
 * Link: https://leetcode.com/problems/longest-resilient-subarray-ii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int ans = 1;
        int n = nums.size();
        
        int i = 0;
        while (i < n) {
            int start = i;
            long long m = nums[i] % k;
            while (i < n && nums[i] % k == m) {
                i++;
            }
            
            int len = i - start;
            long long g = gcd(m, (long long)k);
            long long step = k / g;
            
            int c = (len - 1) / step;
            int L = c * step + 1;
            
            if (L > ans) {
                ans = L;
            }
        }
        
        return ans;
    }
};
