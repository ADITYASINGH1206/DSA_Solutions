/**
 * Problem: Number of Unequal Triplets in Array (2475)
 * Link: https://leetcode.com/problems/number-of-unequal-triplets-in-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        int n = nums.size();
        int left = 0, curr, right;
        for (auto& it : mp) {
            curr = it.second;
            right = n - curr - left;
            ans += (left * curr * right);
            left += it.second;
        }
        return ans;
    }
};
