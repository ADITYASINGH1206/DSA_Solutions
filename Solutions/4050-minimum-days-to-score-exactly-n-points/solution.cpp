/**
 * Problem: Minimum Days to Score Exactly N Points (4050)
 * Link: https://leetcode.com/problems/minimum-days-to-score-exactly-n-points/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(int n) {
        vector<int> dp(n + 1, 1e9);
        dp[0] = -1; 
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * (j + 1) / 2 <= i; j++) {
                int points = j * (j + 1) / 2;
                dp[i] = min(dp[i], j + 1 + dp[i - points]);
            }
        }
        
        return dp[n];
    }
};
