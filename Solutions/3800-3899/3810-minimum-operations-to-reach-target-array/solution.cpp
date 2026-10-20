/**
 * Problem: Minimum Operations to Reach Target Array (3810)
 * Link: https://leetcode.com/problems/minimum-operations-to-reach-target-array/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_set<int> s;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != target[i]) s.insert(nums[i]);
        }
        return s.size();
    }
};
