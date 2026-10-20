/**
 * Problem: Check Good Integer (3959)
 * Link: https://leetcode.com/problems/check-good-integer/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkGoodInteger(int n) {
        long long digitSum = 0;
        long long squareSum = 0;
        while(n){
            int digit = n%10;
            int squareDigit = digit*digit;
            digitSum += digit;
            squareSum += squareDigit;
            n/=10;
        }

        return (squareSum-digitSum >= 50);
    }
};
