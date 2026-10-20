/**
 * Problem: Password Strength (3941)
 * Link: https://leetcode.com/problems/password-strength/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int passwordStrength(string password) {
        bool seen[256] = {false}; 
        int strength = 0;
        
        for (char c : password) {
            if (!seen[c]) {
                seen[c] = true;
                if (c >= 'a' && c <= 'z') {
                    strength += 1;
                } else if (c >= 'A' && c <= 'Z') {
                    strength += 2;
                } else if (c >= '0' && c <= '9') {
                    strength += 3;
                } else if (c == '!' || c == '@' || c == '#' || c == '$') {
                    strength += 5;
                }
            }
        }
        
        return strength;
    }
};
