/**
 * Problem: Add Digits (258)
 * Link: https://leetcode.com/problems/add-digits/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int& x,int& ans){
        int n = x;
        ans = 0;
        while(n>0){
            int digit = n%10;
            ans+= digit;
            n/=10;
        }

        if(ans>=10) {
            helper(ans,ans);
        } 
    }

    int addDigits(int num) {
        int ans = 0;
        helper(num,ans);
        return ans;
    }
};
