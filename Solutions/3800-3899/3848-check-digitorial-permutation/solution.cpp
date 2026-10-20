/**
 * Problem: Check Digitorial Permutation (3848)
 * Link: https://leetcode.com/problems/check-digitorial-permutation/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int factorial(int d) {
        int fact = 1;
        for (int i = 2; i <= d; ++i) {
            fact *= i;
        }
        return fact;
    }

    bool isDigitorialPermutation(int n) {
        string originalStr = to_string(n);
        

        int sumFact = 0;
        for (char c : originalStr) {
            sumFact += factorial(c - '0');
        }

        string sumStr = std::to_string(sumFact);
        
        sort(originalStr.begin(), originalStr.end());
        sort(sumStr.begin(), sumStr.end());
    
        return originalStr == sumStr;
    }
};
