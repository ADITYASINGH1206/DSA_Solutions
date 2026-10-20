/**
 * Problem: Maximize Sum of Squares of Digits (3723)
 * Link: https://leetcode.com/problems/maximize-sum-of-squares-of-digits/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string ans;
        while (num-- > 0) {
            int digit = min(9, sum);  
            ans += char('0' + digit);
            sum -= digit;
        }

        return sum == 0 ? ans : "";
    }
};
