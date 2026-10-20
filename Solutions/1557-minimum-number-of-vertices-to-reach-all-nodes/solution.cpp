/**
 * Problem: Minimum Number of Vertices to Reach All Nodes (1557)
 * Link: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> vis(n,0);
        for(int i =0;i<edges.size();i++){
            vis[edges[i][1]] = 1;
        }
        for(int i =0;i<n;i++){
            if(vis[i] == 0) ans.push_back(i);
        }
        return ans;
        
    }   
};
