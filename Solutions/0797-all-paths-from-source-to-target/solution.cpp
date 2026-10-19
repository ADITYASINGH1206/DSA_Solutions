/**
 * Problem: All Paths From Source to Target (797)
 * Link: https://leetcode.com/problems/all-paths-from-source-to-target/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& graph,int node,vector<int>& path,vector<vector<int>>& ans){
        int n = graph.size();
        path.push_back(node);
        if(node == n-1) ans.push_back(path);
        else{
            for(auto it: graph[node]){
                dfs(graph,it,path,ans);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(graph,0,path,ans);
        return ans;
    }
};
// class Solution {
// public:
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//         vector<vector<int>> ans;
//         int n = graph.size();
//         queue<vector<int>> q;
//         q.push({0});
//         while(!q.empty()){
//             vector<int> curPath = q.front();
//             int node = curPath.back();
//             q.pop();
//             if(node == n-1){
//                 ans.push_back(curPath);
//             } 
//             for(auto it :graph[node]){
//                 vector<int> newPath = curPath;
//                 newPath.push_back(it);
//                 q.push(newPath);
//             }
//         }
//         return ans;

//     }
// };
