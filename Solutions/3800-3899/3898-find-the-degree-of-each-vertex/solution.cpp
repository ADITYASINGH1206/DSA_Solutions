/**
 * Problem: Find the Degree of Each Vertex (3898)
 * Link: https://leetcode.com/problems/find-the-degree-of-each-vertex/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        
        for (int i = 0; i < n; i++) {
            int cur_deg = 0;
            for (int j = 0; j < n; j++) {
                cur_deg += matrix[i][j];
            }
            ans.push_back(cur_deg);
        }
        
        return ans;
    }
};
