/**
 * Problem: Complete Prime Number (3765)
 * Link: https://leetcode.com/problems/complete-prime-number/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool prime(int& num) {
        if (num <= 1) {
            return false;
        } else if (num == 2) {
            return true;
        } else if (num % 2 == 0) {
            return false;
        } else {
            for (int i = 3; i * i <= num; i += 2) {
                if (num % i == 0) {
                    return false;
                }
            }
        }
        return true;
    }
    bool completePrime(int num) {
        if(!prime(num)){
            return false;
        }
        int x = num;
        while(x){
            if(!prime(x)){
                return false;
            }
            x/=10;
        }
        int p=1;
        while(p<=num/10){
            p*=10;
        }
        x=num;
        while (p > 1) {
            x %= p;
            if (!prime(x))
                return false;
            p /= 10;
        }
        return true;
    }
};
