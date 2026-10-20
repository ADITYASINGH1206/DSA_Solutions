/**
 * Problem: Maximum Product Difference Between Two Pairs (1913)
 * Link: https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int n = nums.size();
        return ((nums[0]*nums[1])-(nums[n-1]*nums[n-2]));
    }
};
