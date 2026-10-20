/**
 * Problem: Maximize Expression of Three Elements (3745)
 * Link: https://leetcode.com/problems/maximize-expression-of-three-elements/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        return nums[0]+nums[1]-nums[nums.size()-1];
    }
};
