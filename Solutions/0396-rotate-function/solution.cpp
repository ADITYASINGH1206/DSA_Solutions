/**
 * Problem: Rotate Function (396)
 * Link: https://leetcode.com/problems/rotate-function/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f = 0, s = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            f += i * nums[i];
            s += nums[i];
        }
        int ans = f;
        for (int i = 1; i < n; ++i) {
            f = f + s - n * nums[n - i];
            ans = max(ans, f);
        }
        return ans;
    }
};
