/**
 * Problem: Rotate String (796)
 * Link: https://leetcode.com/problems/rotate-string/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int k = 0;
        int n = s.size();
        while(k < n){
            char c = s[0];
            s.erase(0,1);
            s += c;
            if (s == goal) return true;
            k++;
        }
        return false;
    }
};
