/**
 * Problem: Combinations (77)
 * Link: https://leetcode.com/problems/combinations/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void combo(vector<vector<int>>& ans, vector<int>& curr, int n, int k, int i) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        for (i; i <= n; i++) {
            curr.push_back(i);
            combo(ans, curr, n, k, i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        int i = 1;
        combo(ans, curr, n, k, i);
        return ans;
    }
};
