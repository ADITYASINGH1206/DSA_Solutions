/**
 * Problem: Minimum Sum of Four Digit Number After Splitting Digits (2160)
 * Link: https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(int num) {
        vector<int> digits;
        int temp = num;
        while(temp != 0){
            int digit = temp%10;
            temp/=10;
            digits.push_back(digit);
        }
        sort(digits.begin(),digits.end());
        int num1 = digits[0]*10 + digits[3];
        int num2 = digits[1]*10 + digits[2];
        return num1+num2;
    }
};
