/**
 * Problem: Mirror Distance of an Integer (3783)
 * Link: https://leetcode.com/problems/mirror-distance-of-an-integer/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        auto reverse = [](int x) -> int {
            int y = 0;
            for (; x; x /= 10) {
                y = y * 10 + x % 10;
            }
            return y;
        };
        return abs(n - reverse(n));
    }
};
