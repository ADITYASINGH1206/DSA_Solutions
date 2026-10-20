/**
 * Problem: Power of Two (231)
 * Link: https://leetcode.com/problems/power-of-two/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        if(n==1) return true;
        if(n%2==0) return isPowerOfTwo(n/2);

        return false;
    }
};
