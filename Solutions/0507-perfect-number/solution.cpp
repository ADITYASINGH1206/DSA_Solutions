/**
 * Problem: Perfect Number (507)
 * Link: https://leetcode.com/problems/perfect-number/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int pf = 0;
        for(int i =1 ; i < num ; i++){
            if(num%i ==0){
            pf += i;
            }
        }
        if(pf == num){
            return true;
        }
        else{
            return false;
        }
    }
};
