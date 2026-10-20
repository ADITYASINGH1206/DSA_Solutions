/**
 * Problem: Maximum Product Pair With Target Sum (4074)
 * Link: https://leetcode.com/problems/maximum-product-pair-with-target-sum/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int max_prod = INT_MIN;
        vector<int> ans = {-1, -1};
        for (int i = 0; i < nums.size(); ++i) {
            int comp = target - nums[i];
            
            if (mp.count(comp) && nums[i] != comp) {
                int j = mp[comp];
                
                int i_larger = (nums[i] > comp) ? i : j;
                int i_smaller = (nums[i] > comp) ? j : i;
                
                int prod = nums[i] * comp;
                if (prod > max_prod) {
                    max_prod = prod;
                    ans = {i_larger, i_smaller};
                }
            }
            mp[nums[i]] = i; 
        }
        
        return ans;
    }
};
