/**
 * Problem: Plus One (66)
 * Link: https://leetcode.com/problems/plus-one/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry =0,sum=0;
        for(int i=digits.size()-1;i>=0;i--){
            if(carry != 0){
                sum = digits[i] +carry;
                carry =0;
            }
            if(i==digits.size()-1){
                sum = digits[i]+1;
            }
            if(sum >=10){
                carry = sum%9;
                digits[i] = sum%10;
            }
            else{
                digits[i] = sum;
            }
            if(carry ==0){
                break;
            }
            
        }
        if(carry!=0){
            digits.insert(digits.begin(),carry);
        }
        return digits;
    }
};
