/**
 * Problem: Move Zeroes (283)
 * Link: https://leetcode.com/problems/move-zeroes/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i]) {
                swap(nums[i], nums[k++]);
            }
        }
    }
};
