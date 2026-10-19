/**
 * Problem: Complement of Base 10 Integer (1009)
 * Link: https://leetcode.com/problems/complement-of-base-10-integer/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        int ans = 0, i = 0;
        while (n != 0) {
            ans |= (n & 1 ^ 1) << (i++);
            n >>= 1;
        }
        return ans;
    }
};
