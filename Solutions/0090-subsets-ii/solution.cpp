/**
 * Problem: Subsets II (90)
 * Link: https://leetcode.com/problems/subsets-ii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void backtrack(int i, vector<int>& nums, vector<int>& subset, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(i + 1, nums, subset, ans);
        subset.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        backtrack(i + 1, nums, subset, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        backtrack(0, nums, subset, ans);
        return ans;        
    }
   
};
