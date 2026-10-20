/**
 * Problem: Sum of Primes Between Number and Its Reverse (3918)
 * Link: https://leetcode.com/problems/sum-of-primes-between-number-and-its-reverse/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        int r = stoi(s);
        
        int start = min(n, r);
        int end = max(n, r);
        
        int ans = 0;
        for (int i = start; i <= end; i++) {
            if(isPrime(i)) {
                ans+= i;
            }
        }
        
        return ans;
    }
};
