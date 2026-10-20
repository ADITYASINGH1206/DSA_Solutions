/**
 * Problem: Find Center of Star Graph (1791)
 * Link: https://leetcode.com/problems/find-center-of-star-graph/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

//O(1)

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int u1 = edges[0][0];
        int v1 = edges[0][1];

        int u2 = edges[1][0];
        int v2 = edges[1][1];

        if (u1 == u2 || u1 == v2) {
            return u1;
        } else {
            return v1;
        }
    }
};



// class Solution {
// public:
//     int findCenter(vector<vector<int>>& edges) {
//         int n = edges.size();
//         vector<int> vis(n+2,0);
//         for(int i = 0;i<n;i++){
//             if(vis[edges[i][0]]) return edges[i][0];
//             if(vis[edges[i][1]]) return edges[i][1];
//             else{
//                 vis[edges[i][0]] = 1;
//                 vis[edges[i][1]] = 1;
//             }
//         }
//         return 0;
//     }
// };
