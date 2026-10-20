/**
 * Problem: Minimum Score of a Path Between Two Cities (2492)
 * Link: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &road : roads){
            int u = road[0];
            int v = road[1];
            int w = road[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<bool> vis(n + 1, false);
        queue<int> q;

        q.push(1);
        vis[1] = true;

        int ans = INT_MAX;

        while(!q.empty()){

            int node = q.front();
            q.pop();

            for(auto &[edge, wt] : adj[node]){

                ans = min(ans, wt);

                if(!vis[edge]){
                    vis[edge] = true;
                    q.push(edge);
                }
            }
        }

        return ans;
    }
};
