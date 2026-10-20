/**
 * Problem: Palindromic Subarray Sum (3985)
 * Link: https://leetcode.com/problems/palindromic-subarray-sum/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }

        int n_T = 2 * n + 1;
        vector<int> T(n_T);
        for (int i = 0; i < n; ++i) {
            T[2 * i] = INT_MAX;
            T[2 * i + 1] = nums[i];
        }
        T[2 * n] = INT_MAX;
        
        vector<int> P(n_T, 0);
        int C = 0, R = -1;
        long long max_sum = LLONG_MIN;

        for (int i = 0; i < n_T; ++i) {
            int rad = (i < R) ? min(R - i, P[2 * C - i]) : 0;

            if (i + rad > R) {
                int L_nums = (i - rad) / 2;
                int R_nums = (i + rad - 1) / 2;
                if (L_nums <= R_nums) {
                    max_sum = max(max_sum, pref[R_nums + 1] - pref[L_nums]);
                }
            }

            while (i - rad - 1 >= 0 && i + rad + 1 < n_T && T[i - rad - 1] == T[i + rad + 1]) {
                rad++;
                if (i + rad > R) {
                    int L_nums = (i - rad) / 2;
                    int R_nums = (i + rad - 1) / 2;
                    if (L_nums <= R_nums) {
                        max_sum = max(max_sum, pref[R_nums + 1] - pref[L_nums]);
                    }
                }
            }
            
            P[i] = rad;
            if (i + rad > R) {
                C = i;
                R = i + rad;
            }
        }
        
        return max_sum;
    }
};
