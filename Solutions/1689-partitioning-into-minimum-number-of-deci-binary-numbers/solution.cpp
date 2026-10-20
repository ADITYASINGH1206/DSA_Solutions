/**
 * Problem: Partitioning Into Minimum Number Of Deci-Binary Numbers (1689)
 * Link: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (char& c : n) {
            ans = max(ans, c - '0');
        }
        return ans;
    }
};
