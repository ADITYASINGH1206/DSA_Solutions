/**
 * Problem: Minimum Cost to Split into Ones (3857)
 * Link: https://leetcode.com/problems/minimum-cost-to-split-into-ones/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n) {

        return (n*(n-1))/2;
    }
};
