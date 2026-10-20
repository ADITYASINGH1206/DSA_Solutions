/**
 * Problem: Find the Difference of Two Arrays (2215)
 * Link: https://leetcode.com/problems/find-the-difference-of-two-arrays/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        vector<vector<int>> ans(2);
        for (int v : s1) {
            if (!s2.contains(v)) {
                ans[0].push_back(v);
            }
        }
        for (int v : s2) {
            if (!s1.contains(v)) {
                ans[1].push_back(v);
            }
        }
        return ans;
    }
};
