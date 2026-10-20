/**
 * Problem: Minimum Number of Flips to Make the Binary String Alternating (1888)
 * Link: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string target = "01";
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != target[i & 1]) {
                ++cnt;
            }
        }
        int ans = min(cnt, n - cnt);
        for (int i = 0; i < n; ++i) {
            if (s[i] != target[i & 1]) {
                --cnt;
            }
            if (s[i] != target[(i + n) & 1]) {
                ++cnt;
            }
            ans = min({ans, cnt, n - cnt});
        }
        return ans;
    }
};
