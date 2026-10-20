/**
 * Problem: Sum of Beauty in the Array (2012)
 * Link: https://leetcode.com/problems/sum-of-beauty-in-the-array/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMin(n);
        rightMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMin[i] = min(rightMin[i + 1], nums[i]);
        }
        int ans = 0;
        int leftMax = nums[0]; 
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > leftMax && nums[i] < rightMin[i + 1]) {
                ans += 2;
            } 
            else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) {
                ans += 1;
            }
            leftMax = max(leftMax, nums[i]);
        }
        
        return ans;
    }
};
