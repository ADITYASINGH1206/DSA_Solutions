/**
 * Problem: Number of Unique XOR Triplets I (3513)
 * Link: https://leetcode.com/problems/number-of-unique-xor-triplets-i/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return n;

        int mask = 0;
        for (int num : nums) {
            mask |= num;
        }

        return mask + 1;
    }
};
