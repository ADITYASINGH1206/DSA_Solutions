/**
 * Problem: Calculate Money in Leetcode Bank (1716)
 * Link: https://leetcode.com/problems/calculate-money-in-leetcode-bank/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int mon = 1;
        int prev = 1;
        for(int i = 1;i<=n;i++){
            if(i%7 == 1){
                ans += mon;
                prev = mon;
                mon++;
            }else{
                ans += prev+1;
                prev += 1;
            }
        }
        return ans;

    }
};
