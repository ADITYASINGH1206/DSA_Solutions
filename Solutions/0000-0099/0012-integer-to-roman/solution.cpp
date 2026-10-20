/**
 * Problem: Integer to Roman (12)
 * Link: https://leetcode.com/problems/integer-to-roman/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<string> symb = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> roman = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans;
        for (int i = 0; i < symb.size(); ++i) {
            while (num >= roman[i]) {
                num -= roman[i];
                ans += symb[i];
            }
        }
        return ans;
    } 
};
