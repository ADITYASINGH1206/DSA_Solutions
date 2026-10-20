/**
 * Problem: Maximum Number of Groups Entering a Competition (2358)
 * Link: https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int k = 0, total = 0, n = grades.size();
        while (total + k + 1 <= n)
            total += ++k;
        return k;
    }
};
