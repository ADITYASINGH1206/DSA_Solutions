/**
 * Problem: Check if Strings Can be Made Equal With Operations II (2840)
 * Link: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<vector<int>> cnt(2, vector<int>(26, 0));
        for (int i = 0; i < s1.size(); ++i) {
            ++cnt[i & 1][s1[i] - 'a'];
            --cnt[i & 1][s2[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[0][i] || cnt[1][i]) {
                return false;
            }
        }
        return true;
    }
};
