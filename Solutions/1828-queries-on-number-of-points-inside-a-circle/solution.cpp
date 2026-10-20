/**
 * Problem: Queries on Number of Points Inside a Circle (1828)
 * Link: https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>ans;
        for(int i = 0 ; i<queries.size();i++){
            int a =queries[i][0],b=queries[i][1],r=queries[i][2];
            int count = 0;
            for(int j = 0 ;j<points.size();j++){
                int x = points[j][0],y=points[j][1];
                if ( (pow(x - a, 2) + pow(y - b, 2)) <= pow(r, 2) ){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
