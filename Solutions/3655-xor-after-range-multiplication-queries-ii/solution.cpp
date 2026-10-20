/**
 * Problem: XOR After Range Multiplication Queries II (3655)
 * Link: https://leetcode.com/problems/xor-after-range-multiplication-queries-ii/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= 1000000007;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % 1000000007;
            base = (base * base) % 1000000007;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, 1000000007 - 2);
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int MOD = 1000000007;
        int n = nums.size();
        
        int B = max(1, (int)sqrt(n));
        
        unordered_map<int, vector<vector<int>>> small_k_queries;

        for (const auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k < B) {
                small_k_queries[k].push_back({l, r, v});
            } else {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            }
        }

        for (auto& pair : small_k_queries) {
            int k = pair.first;
            auto& qs = pair.second;

            vector<long long> mult_diff(n + k, 1);
            vector<int> zero_diff(n + k, 0);

            for (const auto& q : qs) {
                int l = q[0], r = q[1];
                long long v = q[2] % MOD;

                int nxt = l + ((r - l) / k + 1) * k;

                if (v == 0) {
                    zero_diff[l]++;
                    if (nxt < n) zero_diff[nxt]--;
                } else {
                    mult_diff[l] = (mult_diff[l] * v) % MOD;
                    if (nxt < n) {
                        mult_diff[nxt] = (mult_diff[nxt] * modInverse(v)) % MOD;
                    }
                }
            }

            for (int i = 0; i < n; ++i) {
                if (i >= k) {
                    zero_diff[i] += zero_diff[i - k];
                    mult_diff[i] = (mult_diff[i] * mult_diff[i - k]) % MOD;
                }
                if (zero_diff[i] > 0) {
                    nums[i] = 0;
                } else {
                    nums[i] = (1LL * nums[i] * mult_diff[i]) % MOD;
                }
            }
        }

        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }

        return ans;
    }
};
