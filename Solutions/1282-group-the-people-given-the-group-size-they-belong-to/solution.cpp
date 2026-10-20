/**
 * Problem: Group the People Given the Group Size They Belong To (1282)
 * Link: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n; ++i) {
            g[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < g.size(); ++i) {
            for (int j = 0; j < g[i].size(); j += i) {
                vector<int> t(g[i].begin() + j, g[i].begin() + j + i);
                ans.push_back(t);
            }
        }
        return ans;
    }
};
