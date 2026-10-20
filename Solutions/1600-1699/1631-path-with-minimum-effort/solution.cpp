/**
 * Problem: Path With Minimum Effort (1631)
 * Link: https://leetcode.com/problems/path-with-minimum-effort/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
                       
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        pq.push({0, {0, 0}});
        effort[0][0] = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while (!pq.empty()) {
            int dist = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if (row == n - 1 && col == m - 1) {
                return dist;
            }
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int temp = abs(heights[row][col] - heights[nrow][ncol]);
                    int temp2 = max(dist, temp);
                    if (temp2 < effort[nrow][ncol]) {
                        effort[nrow][ncol] = temp2;
                        pq.push({temp2, {nrow, ncol}});
                    }
                }
            }
        }
        
        return 0; 
    }
};
