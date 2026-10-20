/**
 * Problem: Count Good Numbers (1922)
 * Link: https://leetcode.com/problems/count-good-numbers/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;
    
    long long power(long long base, long long exp) {
        long long result = 1;
        base = base % MOD; 
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp = exp / 2;
        }
        
        return result;
    }

public:
    int countGoodNumbers(long long n) {
        long long even_pos = (n + 1) / 2;
        long long odd_pos = n / 2;
        
        long long even_c = power(5, even_pos);
        long long odd_c = power(4, odd_pos);
        
        return (even_c * odd_c) % MOD;
    }
};
