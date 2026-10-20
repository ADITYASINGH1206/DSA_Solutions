/**
 * Problem: Partition Array Such That Maximum Difference Is K (2294)
 * Link: https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int ans = 1; 
        int min_val = nums[0]; 
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] - min_val > k) {
                ans++;
                min_val = nums[i]; 
            }
        }
        
        return ans;
    }
};
