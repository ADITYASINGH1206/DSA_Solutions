/**
 * Problem: Combination Sum II (40)
 * Link: https://leetcode.com/problems/combination-sum-ii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int target,int idx,vector<int>& candidates,vector<vector<int>>& ans,vector<int>& cur){
        if(target <0) return;
        if(target == 0){
            ans.push_back(cur);
            return;
        }

        for(int i = idx;i<candidates.size();i++){
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] > target) {
                break;
            }
            cur.push_back(candidates[i]);
            backtrack(target-candidates[i],i+1,candidates,ans,cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> cur;
        backtrack(target,0,candidates,ans,cur);
        return ans;
    }
};
