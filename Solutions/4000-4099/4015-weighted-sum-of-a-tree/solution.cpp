/**
 * Problem: Weighted Sum of a Tree (4015)
 * Link: https://leetcode.com/problems/weighted-sum-of-a-tree/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                root = i;
            } else {
                adj[parent[i]].push_back(i);
            }
        }

        vector<int> depth(n, 0);
        int maxDepth = 0;
        queue<int> q;
        if (root != -1) {
            q.push(root);
            depth[root] = 1;
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            maxDepth = max(maxDepth, depth[curr]);
            for (int child : adj[curr]) {
                depth[child] = depth[curr] + 1;
                q.push(child);
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += 1LL * nums[i] * (maxDepth - depth[i] + 1);
        }

        return ans;
    }
};
