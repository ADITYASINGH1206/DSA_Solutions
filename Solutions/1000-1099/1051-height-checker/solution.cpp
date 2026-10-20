/**
 * Problem: Height Checker (1051)
 * Link: https://leetcode.com/problems/height-checker/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());
        int ans = 0;
        for (int i = 0; i < heights.size(); ++i) {
            ans += heights[i] != expected[i];
        }
        return ans;
    }
};
