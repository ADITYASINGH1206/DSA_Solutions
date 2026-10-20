/**
 * Problem: Valid Digit Number (3908)
 * Link: https://leetcode.com/problems/valid-digit-number/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validDigit(int n, int x) {
        if (n == 0) return false;
        
        int temp = n;
        bool found = false;
        int first = 0;
        
        while (temp) {
            int digit = temp % 10;
            if (digit == x) {
                found = true; 
            }
            temp /= 10;
            if (temp == 0) {
                first = digit;
            }
        }

        return found && (first != x);
    }
};
