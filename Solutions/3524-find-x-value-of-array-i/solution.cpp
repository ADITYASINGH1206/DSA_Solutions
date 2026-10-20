/**
 * Problem: Find X Value of Array I (3524)
 * Link: https://leetcode.com/problems/find-x-value-of-array-i/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k), state(k);
        for (int value : nums) {
            int rem = value % k;
            vector<long long> next(k);
            for (int r = 0; r < k; r++) {
                int productRem = (r * rem) % k;
                next[productRem] += state[r];
                ans[productRem] += state[r];
            }
            next[rem]++;
            ans[rem]++;
            state = next;
        }
        return ans;
    }
};
