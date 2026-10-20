/**
 * Problem: Pythagorean Distance Nodes in a Tree (3820)
 * Link: https://leetcode.com/problems/pythagorean-distance-nodes-in-a-tree/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:

    void bfs(int start, int n, const vector<vector<int>>& adj, vector<int>& dist) {
        fill(dist.begin(), dist.end(), -1); 
        queue<int> q;
        
        q.push(start);
        dist[start] = 0;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                if (dist[v] == -1) { 
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {

        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
    
        vector<int> distX(n), distY(n), distZ(n);
        
        // Run BFS from each target node
        bfs(x, n, adj, distX);
        bfs(y, n, adj, distY);
        bfs(z, n, adj, distZ);
        
        int specialCount = 0;
    
        for (int i = 0; i < n; i++) {
            long long d1 = distX[i];
            long long d2 = distY[i];
            long long d3 = distZ[i];
            
            vector<long long> d = {d1, d2, d3};
            sort(d.begin(), d.end()); 

            if (d[0] * d[0] + d[1] * d[1] == d[2] * d[2]) {
                specialCount++;
            }
        }
        
        return specialCount;
    }
};
