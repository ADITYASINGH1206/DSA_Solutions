/**
 * Problem: Find The Original Array of Prefix Xor (2433)
 * Link: https://leetcode.com/problems/find-the-original-array-of-prefix-xor/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans = {pref[0]};
        for (int i = 1; i < n; ++i) {
            ans.push_back(pref[i - 1] ^ pref[i]);
        }
        return ans;
    }
};
