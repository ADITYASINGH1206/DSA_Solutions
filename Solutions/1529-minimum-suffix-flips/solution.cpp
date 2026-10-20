/**
 * Problem: Minimum Suffix Flips (1529)
 * Link: https://leetcode.com/problems/minimum-suffix-flips/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string target) {
        int n = target.size();
        int ans = 0;
        if (target[0] == '1') ans++;
        for (int i = 0; i < n - 1; i++) {
            if (target[i] != target[i+1]) {
                ans++;
            }
        }

        return ans;
    }
};
