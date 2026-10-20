/**
 * Problem: Valid Elements in an Array (3912)
 * Link: https://leetcode.com/problems/valid-elements-in-an-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return nums;
        
        vector<bool> valid(n, false);
        valid[0] = true;
        valid[n - 1] = true;
        
        int max_left = nums[0];
        int max_right = nums[n - 1];
        
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > max_left) valid[i] = true;
            max_left = max(max_left, nums[i]);
            
            int j = n - 1 - i; 
            if (nums[j] > max_right) valid[j] = true;
            max_right = max(max_right, nums[j]);
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (valid[i]) {
                result.push_back(nums[i]);
            }
        }
        
        return result;
    }
};
