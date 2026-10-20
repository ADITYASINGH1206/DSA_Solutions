/**
 * Problem: Course Schedule (207)
 * Link: https://leetcode.com/problems/course-schedule/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
//         vis[node] = 1;
//         pathVis[node] = 1; 

//         for (auto it : adj[node]) {
//             if (!vis[it]) {
//                 if (dfs(it, adj, vis, pathVis)) return true;
//             }
//             else if (pathVis[it] == 1) {
//                 return true;
//             }
//         }

//         pathVis[node] = 0;
//         return false;
//     }

//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> adj(numCourses);
//         for (auto& pre : prerequisites) {
//             adj[pre[1]].push_back(pre[0]);
//         }

//         vector<int> vis(numCourses, 0);
//         vector<int> pathVis(numCourses, 0);

//         for (int i = 0; i < numCourses; i++) {
//             if (!vis[i]) {
//                 if (dfs(i, adj, vis, pathVis) == true) {
//                     return false;
//                 }
//             }
//         }

//         return true; 
//     }
// };

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> indegree(numCourses,0);
        for(int i = 0;i<numCourses;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i = 0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }

        }
        if(topo.size() == numCourses) return true;
        return false;
    }
};
