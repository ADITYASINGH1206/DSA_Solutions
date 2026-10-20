/**
 * Problem: Reverse String Prefix (3794)
 * Link: https://leetcode.com/problems/reverse-string-prefix/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reversePrefix(string s, int k) {
        string t = s.substr(0, k);
        reverse(t.begin(), t.end());
        return t + s.substr(k);
    }
};
