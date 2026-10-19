/**
 * Problem: Prime Number of Set Bits in Binary Representation (762)
 * Link: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes{2, 3, 5, 7, 11, 13, 17, 19};
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            ans += primes.count(__builtin_popcount(i));
        }
        return ans;
    }
};
