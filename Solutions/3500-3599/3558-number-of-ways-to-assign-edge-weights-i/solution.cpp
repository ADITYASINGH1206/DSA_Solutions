/**
 * Problem: Number of Ways to Assign Edge Weights I (3558)
 * Link: https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxHeight = 0;


    long long powerMod(long long base, long long exp) {
        long long result = 1;
        base %= MOD;

        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }

        return result;
    }

    void dfs(int node, int parent, int depth, const vector<vector<int>>& adj) {
        maxHeight = max(maxHeight, depth);
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, depth + 1, adj);
            }
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        maxHeight = 0;
        dfs(1, -1, 0, adj); 

        if (maxHeight == 0) return 1;

        return powerMod(2, maxHeight - 1); 
    }
};
