/**
 * Problem: Check if All A's Appears Before All B's (2124)
 * Link: https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        for(int i = 1;i<n;i++){
            if(s[i]=='a'&& s[i-1] == 'b') return false;
        }
        return true;
    }
};
