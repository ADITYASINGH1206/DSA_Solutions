/**
 * Problem: Concatenate Non-Zero Digits and Multiply by Sum I (3754)
 * Link: https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        long long place = 1;

        while (n > 0) {
            int d = n % 10;
            if (d != 0) {
                x = d * place + x;
                place *= 10;
                sum += d;
            }
            n /= 10;
        }

        return x * sum;
    }
};
