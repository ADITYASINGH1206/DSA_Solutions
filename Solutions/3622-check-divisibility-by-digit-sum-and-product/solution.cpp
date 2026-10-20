/**
 * Problem: Check Divisibility by Digit Sum and Product (3622)
 * Link: https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int sumDigit = 0;
        int productDigit = 1;
        int num = n;


        while (num > 0) {
            sumDigit += num % 10;
            productDigit *= num % 10;
            num /= 10;
        }


        return n % (sumDigit + productDigit) == 0;
    }
};
