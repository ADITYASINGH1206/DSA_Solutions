/**
 * Problem: Binary Gap (868)
 * Link: https://leetcode.com/problems/binary-gap/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        for (int pre = 100, cur = 0; n != 0; n >>= 1) {
            if (n & 1) {
                ans = max(ans, cur - pre);
                pre = cur;
            }
            ++cur;
        }
        return ans;
    }
};
