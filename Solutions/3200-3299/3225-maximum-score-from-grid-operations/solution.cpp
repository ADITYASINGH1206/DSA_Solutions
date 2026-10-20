/**
 * Problem: Maximum Score From Grid Operations (3225)
 * Link: https://leetcode.com/problems/maximum-score-from-grid-operations/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<long long>> col_sum(n, vector<long long>(n + 1, 0));
        for (int c = 0; c < n; ++c) {
            for (int r = 0; r < n; ++r) {
                col_sum[c][r + 1] = col_sum[c][r] + grid[r][c];
            }
        }
        
        const long long INF = 1e18; 
        
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -INF));
        
        for (int v = 0; v <= n; ++v) {
            dp[0][v] = 0;
        }
        
        for (int i = 0; i < n; ++i) {
            vector<vector<long long>> next_dp(n + 1, vector<long long>(n + 1, -INF));
            const vector<long long>& base_sum = col_sum[i];
            
            for (int v = 0; v <= n; ++v) {
                long long val_v = base_sum[v];
                vector<long long> pref(n + 1, -INF);
                long long curr_max = -INF;
                for (int w = 0; w <= n; ++w) {
                    if (dp[w][v] > curr_max) {
                        curr_max = dp[w][v];
                    }
                    pref[w] = curr_max;
                }
                vector<long long> suff(n + 1, -INF);
                curr_max = -INF;
                for (int w = n - 1; w >= 0; --w) {
                    int u = w + 1;
                    long long cst = (u > v) ? (base_sum[u] - val_v) : 0;
                    
                    if (dp[u][v] != -INF) {
                        long long val = dp[u][v] + cst;
                        if (val > curr_max) {
                            curr_max = val;
                        }
                    }
                    suff[w] = curr_max;
                }
                for (int w = 0; w <= n; ++w) {
                    long long ans = suff[w];
                    long long p = pref[w];
                    
                    if (p != -INF) {
                        long long cst = (w > v) ? (base_sum[w] - val_v) : 0;
                        long long cand = p + cst;
                        if (cand > ans) {
                            ans = cand;
                        }
                    }
                    next_dp[v][w] = ans;
                }
            }
            dp = move(next_dp);
        }
        
        long long max_score = 0;
        for (int v = 0; v <= n; ++v) {
            max_score = max(max_score, dp[v][0]);
        }
        
        return max_score;
    }
};
