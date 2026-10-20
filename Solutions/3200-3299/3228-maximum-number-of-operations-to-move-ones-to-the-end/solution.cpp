/**
 * Problem: Maximum Number of Operations to Move Ones to the End (3228)
 * Link: https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        int ones = 0, res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1')
                ones++;
            else if ((i > 0) && s[i - 1] == '1')
                res += ones;
        }

        return res;
    }
};
