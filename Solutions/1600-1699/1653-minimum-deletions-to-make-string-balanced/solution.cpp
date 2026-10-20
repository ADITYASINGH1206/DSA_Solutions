/**
 * Problem: Minimum Deletions to Make String Balanced (1653)
 * Link: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0, b = 0;
        for (char& c : s) {
            if (c == 'b') {
                ++b;
            } else {
                ans = min(ans + 1, b);
            }
        }
        return ans;
    }
};
