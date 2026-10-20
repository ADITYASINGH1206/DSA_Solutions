/**
 * Problem: Sorted GCD Pair Queries (3312)
 * Link: https://leetcode.com/problems/sorted-gcd-pair-queries/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxE = *max_element(nums.begin(), nums.end());

        vector<long long> freq(maxE + 1, 0);
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        vector<long long> exact(maxE + 1, 0);

        for (int gcd = maxE; gcd >= 1; gcd--) {
            long long cnt = 0;

            for (int times = gcd; times <= maxE; times += gcd) {
                cnt += freq[times];
            }

            exact[gcd] = cnt * (cnt - 1) / 2;

            for (int times = 2 * gcd; times <= maxE; times += gcd) {
                exact[gcd] -= exact[times];
            }
        }

        vector<long long> pref(maxE + 1, 0);
        for (int gcd = 1; gcd <= maxE; gcd++) {
            pref[gcd] = pref[gcd - 1] + exact[gcd];
        }

        vector<int> result;
        for (long long q : queries) {
            int gcd = lower_bound(pref.begin() + 1, pref.end(), q + 1) - pref.begin();
            result.push_back(gcd);
        }

        return result;
    }
};
