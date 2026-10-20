/**
 * Problem: Harshad Number (3099)
 * Link: https://leetcode.com/problems/harshad-number/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum_d = 0;
        int temp = x;
        while(x){
            int digit = x%10;
            x/=10;
            sum_d += digit;
        }
        if(temp%sum_d == 0) return sum_d;
        return -1;
    }
};
