/**
 * Problem: XOR After Range Multiplication Queries I (3653)
 * Link: https://leetcode.com/problems/xor-after-range-multiplication-queries-i/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int mod = 1e9 + 7;
        for (const auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = 1LL * nums[idx] * v % mod;
            }
        }
        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }
        return ans;
    }
};
