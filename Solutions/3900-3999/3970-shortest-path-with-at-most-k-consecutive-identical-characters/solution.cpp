/**
 * Problem: Shortest Path With At Most K Consecutive Identical Characters (3970)
 * Link: https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto e = pq.top(); pq.pop();
            long long d = e[0];
            int u = e[1];
            int cur = e[2];

            if (d != dist[u][cur]) continue;

            for (auto &vec : adj[u]) {
                int v = vec.first, w = vec.second;
                int newcur = (labels[v] == labels[u]) ? cur + 1 : 1;
                if (newcur > k) continue;

                if (dist[v][newcur] > d + w) {
                    dist[v][newcur] = d + w;
                    pq.push({dist[v][newcur], v, newcur});
                }
            }
        }

        long long ans = LLONG_MAX;
        for (int i = 1; i <= k; i++) ans = min(ans, dist[n - 1][i]);
        return ans == LLONG_MAX ? -1 : ans;
    }
};
