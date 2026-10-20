/**
 * Problem: Count Number of Maximum Bitwise-OR Subsets (2044)
 * Link: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count = 0; 
    void helper(vector<int>& nums, int index, int currentOr, int maxOr) {
        if (index == nums.size()) {
            if (currentOr == maxOr) {
                count++;
            }
            return;
        }
        helper(nums, index + 1, currentOr | nums[index], maxOr);
        helper(nums, index + 1, currentOr, maxOr);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int num : nums) {
            maxOr |= num;
        }
        helper(nums, 0, 0, maxOr);

        return count;
    }
};
