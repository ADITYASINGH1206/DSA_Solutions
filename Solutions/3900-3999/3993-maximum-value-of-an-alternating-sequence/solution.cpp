/**
 * Problem: Maximum Value of an Alternating Sequence (3993)
 * Link: https://leetcode.com/problems/maximum-value-of-an-alternating-sequence/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumValue(long long n, long long s, long long m) {
        if (n == 1) return s;
        
        long long up = n / 2; 
        long long dn = up - 1; 
        
        return s + (up * m) - dn;
    }
};
