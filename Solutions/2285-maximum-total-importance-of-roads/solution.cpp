/**
 * Problem: Maximum Total Importance of Roads (2285)
 * Link: https://leetcode.com/problems/maximum-total-importance-of-roads/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n, 0);
        for (const auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        sort(degree.begin(), degree.end());
        
        long long ans = 0;
        for (long long i = 0; i < n; i++) {
            ans += degree[i] * (i + 1);
        }
        
        return ans;
    }
};
