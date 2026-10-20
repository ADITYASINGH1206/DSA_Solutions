/**
 * Problem: Minimum Cuts to Divide a Circle (2481)
 * Link: https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfCuts(int n) {
        if(n==1)return 0;
        if (n % 2 == 0) return n / 2;
        return n;
    }
};
