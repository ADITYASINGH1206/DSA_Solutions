/**
 * Problem: Find Champion II (2924)
 * Link: https://leetcode.com/problems/find-champion-ii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> winners(100,0);
        for(int i = 0;i<edges.size();i++){
            winners[edges[i][1]] = -1;
        }
        int ans = -1;
        for(int i = 0;i<n;i++){
            if(winners[i] == 0){
                if(ans != -1) return -1;
                else ans = i;
            }
        }
        return ans;
    }
};
