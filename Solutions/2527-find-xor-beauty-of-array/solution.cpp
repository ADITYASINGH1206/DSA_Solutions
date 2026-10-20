/**
 * Problem: Find Xor-Beauty of Array (2527)
 * Link: https://leetcode.com/problems/find-xor-beauty-of-array/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int ans = 0;
        for (int& x : nums) {
            ans ^= x;
        }
        return ans;
    }
};
