/**
 * Problem: Minimum Total Cost to Process All Elements (3987)
 * Link: https://leetcode.com/problems/minimum-total-cost-to-process-all-elements/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1000000007;

    long long sum_n(long long n) {
        if (n % 2 == 0) {
            return ((n / 2) % MOD) * ((n + 1) % MOD) % MOD;
        } else {

            return (n % MOD) * (((n + 1) / 2) % MOD) % MOD;
        }
    }


    int minimumCost(vector<int>& nums, int k) {
        long long cr = k;
        long long ops = 0;
        long long ans = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (cr < nums[i]) {
                long long need = nums[i] - cr;
                long long refil = (need + k - 1) / k;
                long long dif = (sum_n(ops + refil) - sum_n(ops) + MOD) % MOD;

                ans = (ans + dif) % MOD;
                cr += refil * (long long)k;
                ops += refil;
            }
            cr -= nums[i];
        }
        
        return ans;
    }
};
