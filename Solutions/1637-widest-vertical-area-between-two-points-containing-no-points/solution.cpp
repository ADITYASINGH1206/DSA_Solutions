/**
 * Problem: Widest Vertical Area Between Two Points Containing No Points (1637)
 * Link: https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans = 0;
        for(int i =0;i<points.size()-1;i++){
            ans = max(ans,points[i+1][0] - points[i][0]);
        }
        return ans;
    }
};
