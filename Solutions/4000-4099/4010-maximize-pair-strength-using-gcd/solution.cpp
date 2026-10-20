/**
 * Problem: Maximize Pair Strength Using GCD (4010)
 * Link: https://leetcode.com/problems/maximize-pair-strength-using-gcd/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        ll ans =0;
        for(int i=0;i<n;i++){
            for(int j =i+1;j<n;j++){
                ll g = gcd(nums[i], nums[j]);
                ll strength = (1LL * nums[i] * nums[j]) / (g * g);
                ans = max(ans, strength);
            }
        }
        return ans;
    }
};
