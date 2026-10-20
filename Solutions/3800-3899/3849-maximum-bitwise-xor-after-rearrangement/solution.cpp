/**
 * Problem: Maximum Bitwise XOR After Rearrangement (3849)
 * Link: https://leetcode.com/problems/maximum-bitwise-xor-after-rearrangement/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumXor(string s,string t) {
        int zeros = 0;
        int ones = 0;
        for (char c : t) {
            if (c == '0') zeros++;
            else ones++;
        }
        
        string result = "";
        
        for (char c : s) {
            if (c == '1') {
                if (zeros > 0) {
                    result += '1';
                    zeros--;
                } else {
                    result += '0';
                    ones--;
                }
            } else { 
                if (ones > 0) {
                    result += '1';
                    ones--;
                } else {
                    result += '0';
                    zeros--;
                }
            }
        }
        
        return result;
    }
};
