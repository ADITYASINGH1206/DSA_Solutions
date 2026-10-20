/**
 * Problem: Strong Password Checker II (2299)
 * Link: https://leetcode.com/problems/strong-password-checker-ii/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n = password.size();
        if(n<8){
            return false;
        }
        bool upper = false;
        bool lower = false;
        bool digit = false;
        bool special = false;
        for(int i =0;i<n;i++){
            if(i>0&&password[i]==password[i-1]){
                return false;
            }else if(isupper(password[i])){
                upper=true;
            }else if(islower(password[i])){
                lower=true;
            }else if(isdigit(password[i])){
                digit=true;
            }else if(ispunct(password[i])){
                special=true;
            }
        }
        if(upper&&lower&&digit&&special){
            return true;
        }
        return false;
    }
};
