/**
 * Problem: Sum of All Subset XOR Totals (1863)
 * Link: https://leetcode.com/problems/sum-of-all-subset-xor-totals/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
    int bits = 0;
    for (int x : nums) bits |= x;
    return bits << (nums.size() - 1);
    }
};
