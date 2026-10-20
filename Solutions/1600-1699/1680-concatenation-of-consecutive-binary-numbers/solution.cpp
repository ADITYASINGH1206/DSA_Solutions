/**
 * Problem: Concatenation of Consecutive Binary Numbers (1680)
 * Link: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        const int mod = 1e9 + 7;
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = (ans << (32 - __builtin_clz(i)) | i) % mod;
        }
        return ans;
    }
};
