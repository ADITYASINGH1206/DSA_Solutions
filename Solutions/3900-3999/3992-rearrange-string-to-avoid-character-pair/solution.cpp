/**
 * Problem: Rearrange String to Avoid Character Pair (3992)
 * Link: https://leetcode.com/problems/rearrange-string-to-avoid-character-pair/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string ys = "";
        string xs = "";
        string others = "";
        
        for (char c : s) {
            if (c == y) {
                ys += c;
            } else if (c == x) {
                xs += c;
            } else {
                others += c;
            }
        }
        
        string ans = ys + others + xs;
        
        return ans;
    }
};
