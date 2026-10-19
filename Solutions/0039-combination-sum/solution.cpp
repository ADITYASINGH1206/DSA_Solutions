/**
 * Problem: Combination Sum (39)
 * Link: https://leetcode.com/problems/combination-sum/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& cur, int start) {
        if (target < 0) return; 
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        for(int i = start; i < candidates.size(); i++) {
            cur.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], ans, cur, i);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; 
        vector<int> cur;
        backtrack(candidates, target, ans, cur, 0); 
        return ans;
    }
};
