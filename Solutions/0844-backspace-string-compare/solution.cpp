/**
 * Problem: Backspace String Compare (844)
 * Link: https://leetcode.com/problems/backspace-string-compare/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size();
        string s1;
        for(int i = 0;i<n;i++){
            if(s[i] == '#' && s1.empty()) continue;
            if(s[i] == '#' && !s1.empty()){
                s1.pop_back();
            }
            else{
                s1 += s[i];
            }
        }
    
        n = t.size();
        string s2;
        for(int i = 0;i<n;i++){
            if(t[i] == '#' && s2.empty()) continue;
            if(t[i] == '#' && !s2.empty()){
                s2.pop_back();
            }
            else{
                s2 += t[i];
            }
        }

        return (s1 == s2);
    }
};
