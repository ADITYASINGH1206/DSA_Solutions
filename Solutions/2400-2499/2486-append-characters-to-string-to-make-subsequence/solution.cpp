/**
 * Problem: Append Characters to String to Make Subsequence (2486)
 * Link: https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int si = 0;
        int ti = 0;
        int n = s.length();
        int m = t.length();
    
        while (si < n && ti < m) {
            if (s[si] == t[ti]) {
                ti++;
            }
            si++;
        }
    
        return m - ti;
    }
};
