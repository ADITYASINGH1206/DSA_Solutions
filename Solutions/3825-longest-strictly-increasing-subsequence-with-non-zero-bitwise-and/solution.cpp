/**
 * Problem: Longest Strictly Increasing Subsequence With Non-Zero Bitwise AND (3825)
 * Link: https://leetcode.com/problems/longest-strictly-increasing-subsequence-with-non-zero-bitwise-and/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        vector<int> copy = nums;
        int n = copy.size();
        if (n == 0) return 0;
        
        int ans = 0;
        for (int bit = 0; bit <= 30; ++bit) {
            
           vector<int> tails;
            for (int x : copy) {
                if ((x >> bit) & 1) {
                    auto it = lower_bound(tails.begin(), tails.end(), x);
                    
                    if (it == tails.end()) {
                        tails.push_back(x);
                    } else {
                        *it = x;
                    }
                }
            }
            
            ans = max(ans, (int)tails.size());
        }
        
        return ans;
    }
};
