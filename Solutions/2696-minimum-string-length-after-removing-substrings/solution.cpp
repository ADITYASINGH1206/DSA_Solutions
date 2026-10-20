/**
 * Problem: Minimum String Length After Removing Substrings (2696)
 * Link: https://leetcode.com/problems/minimum-string-length-after-removing-substrings/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        string out = "";
        for(int i = 0;i<n;i++){
            if(out.empty()) out.push_back(s[i]);
            else{
                if(out.back() == 'A' && s[i] == 'B') out.pop_back();
                else if(out.back() == 'C' && s[i] == 'D') out.pop_back();
                else out.push_back(s[i]);
            }
        }
        return out.size();
    }
};
