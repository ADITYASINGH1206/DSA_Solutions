/**
 * Problem: Count the Digits That Divide a Number (2520)
 * Link: https://leetcode.com/problems/count-the-digits-that-divide-a-number/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigits(int num) {
        int ans = 0;
        int n = num;
        while(n>0){
            if(num%(n%10)==0) ans++;
            n = n/10;
        }
        return ans;
    }
};
