/**
 * Problem: Minimum Flips to Make Binary String Coherent (3922)
 * Link: https://leetcode.com/problems/minimum-flips-to-make-binary-string-coherent/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        if (n <= 2) return 0;
        int ones = 0;
        for (char c : s) {
            if (c == '1') ones++;
        }
        
        int ans = min(ones, n - ones); 
        if (ones > 0) {
            ans = min(ans, ones - 1); 
        } else {
            ans = min(ans, 1);
        }
        int mid_ones = ones;
        if (s[0] == '1') mid_ones--;
        if (s[n - 1] == '1') mid_ones--;
        int cost_ends = (s[0] == '0' ? 1 : 0) + (s[n - 1] == '0' ? 1 : 0) + mid_ones;
        
        ans = min(ans, cost_ends);
        
        return ans;
    }
};
