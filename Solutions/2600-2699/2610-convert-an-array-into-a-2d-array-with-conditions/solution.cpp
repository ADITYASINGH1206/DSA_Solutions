/**
 * Problem: Convert an Array Into a 2D Array With Conditions (2610)
 * Link: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> cnt(n + 1);
        for (int& x : nums) {
            ++cnt[x];
        }
        for (int x = 1; x <= n; ++x) {
            int v = cnt[x];
            for (int j = 0; j < v; ++j) {
                if (ans.size() <= j) {
                    ans.push_back({});
                }
                ans[j].push_back(x);
            }
        }
        return ans;
    }
};
