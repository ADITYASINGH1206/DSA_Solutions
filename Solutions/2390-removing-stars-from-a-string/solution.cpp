/**
 * Problem: Removing Stars From a String (2390)
 * Link: https://leetcode.com/problems/removing-stars-from-a-string/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                ans.push_back(s[i]);
            } else {
                if (!ans.empty()) {
                    ans.pop_back();
                } else {
                    ans.push_back(s[i]);
                }
            }
        }

        return ans;
    }
};
