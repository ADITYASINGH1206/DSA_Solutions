/**
 * Problem: Network Delay Time (743)
 * Link: https://leetcode.com/problems/network-delay-time/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans = 0;
        vector<pair<int,int>> adj[n+1];
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n+1,1e9);
        dist[k] = 0;
        queue<pair<int,int>> q;
        q.push({k,0});
        while(!q.empty()){
            int node = q.front().first;
            int cost = q.front().second;

            q.pop();

            for(auto it : adj[node]){
                int adjNode = it.first;
                int edW = it.second;
                if(dist[adjNode] > cost + edW){
                    dist[adjNode] = cost + edW;
                    q.push({adjNode,cost+edW});
                }
            }
        }

        for(int i = 1;i<=n;i++){
            if(dist[i] == 1e9) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;

    }
};
