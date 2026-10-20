/**
 * Problem: Longest Subsequence With Non-Zero Bitwise XOR (3702)
 * Link: https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        auto tot = 0, nonZero = 0;

        for (auto& n : nums) {
            nonZero |= n > 0;
            tot ^= n;
        }

        return nonZero * (nums.size() - !tot);
    }
};
