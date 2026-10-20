/**
 * Problem: Minimum Adjacent Swaps to Partition Array (3994)
 * Link: https://leetcode.com/problems/minimum-adjacent-swaps-to-partition-array/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        long long MOD = 1e9 + 7;
        long long ans = 0;
        long long ga = 0; 
        for (int num : nums) {
            if (num < a) {
                ans = (ans + ga) % MOD;
            } else {
                ga++;
            }
        }
        long long gb = 0;
        for (int num : nums) {
            if (num < a) {
                continue; 
            } else if (num > b) {
                gb++;
            } else {
                ans = (ans + gb) % MOD;
            }
        }
        
        return ans;
    }
};
