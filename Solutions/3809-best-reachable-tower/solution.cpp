/**
 * Problem: Best Reachable Tower (3809)
 * Link: https://leetcode.com/problems/best-reachable-tower/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int m = INT_MIN;
        vector<int>ans(2,-1);
        for(int i = 0 ; i<towers.size();i++){
            int dist = abs(towers[i][0]-center[0])+abs(towers[i][1]-center[1]);
            if(dist<=radius){
                if(towers[i][2]>m){
                    ans={towers[i][0],towers[i][1]};
                    m=towers[i][2];
                }else if(towers[i][2]==m){
                    ans=min(ans,{towers[i][0],towers[i][1]});
                }
            }
        }
        return ans;
    }
};
