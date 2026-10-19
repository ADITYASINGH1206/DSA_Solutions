/**
 * Problem: K Closest Points to Origin (973)
 * Link: https://leetcode.com/problems/k-closest-points-to-origin/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < points.size(); ++i) {
            int d = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push({d, i});
            if ((int)pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
