/**
 * Problem: Largest Odd Number in String (1903)
 * Link: https://leetcode.com/problems/largest-odd-number-in-string/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        for (int i = n - 1; i >= 0; --i) {
            int c = num[i] - '0';
            if (c%2 != 0) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
