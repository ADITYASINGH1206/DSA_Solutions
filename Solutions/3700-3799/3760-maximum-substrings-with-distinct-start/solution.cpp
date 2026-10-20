/**
 * Problem: Maximum Substrings With Distinct Start (3760)
 * Link: https://leetcode.com/problems/maximum-substrings-with-distinct-start/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinct(string s) {
        int ans = 0;
        int cnt[26]{};
        for (char c : s) {
            if (++cnt[c - 'a'] == 1) {
                ++ans;
            }
        }
        return ans;
    }
};
