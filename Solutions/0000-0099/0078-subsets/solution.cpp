/**
 * Problem: Subsets (78)
 * Link: https://leetcode.com/problems/subsets/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int i,vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[i]);
        backtrack(i+1,nums,ds,ans);
        ds.pop_back();
        backtrack(i+1,nums,ds,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        backtrack(0,nums,ds,ans);
        return ans;
    }
};
