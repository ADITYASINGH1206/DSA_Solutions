/**
 * Problem: Sum of GCD of Formed Pairs (3867)
 * Link: https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int maxi = -1;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            prefixGcd[i] = gcd(nums[i], maxi);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;
        int l = 0;
        int r = n - 1;

        while (l < r) {
            ans += gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }

        return ans;
    }
};
