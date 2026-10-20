/**
 * Problem: Largest Positive Integer That Exists With Its Negative (2441)
 * Link: https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = -1;
        for (int num : nums) {
            if (num > 0 && st.count(-num))
                ans = max(ans, num);
        }

        return ans;
    }
};
