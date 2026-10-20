/**
 * Problem: Maximum Length Substring With Two Occurrences (3090)
 * Link: https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> m;
        int i = 0, j = 0, n = s.size();
        int res = 0;    
        while (j < n) {
            m[s[j]]++;
            while (m[s[j]] > 2) {
                m[s[i]]--;
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};
