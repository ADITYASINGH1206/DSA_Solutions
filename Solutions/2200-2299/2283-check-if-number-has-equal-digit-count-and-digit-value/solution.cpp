/**
 * Problem: Check if Number Has Equal Digit Count and Digit Value (2283)
 * Link: https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool digitCount(string num) {
        vector<int>freq(10,0);
        for(char ch :num){
            freq[ch-'0']++;
        }
        for(int i = 0 ;i<num.size();i++){
            if(freq[i]!=num[i]-'0'){
                return false;
            }
        }
        return true;
    }
};
