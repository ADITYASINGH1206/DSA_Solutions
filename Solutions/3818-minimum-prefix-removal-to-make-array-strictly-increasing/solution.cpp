/**
 * Problem: Minimum Prefix Removal to Make Array Strictly Increasing (3818)
 * Link: https://leetcode.com/problems/minimum-prefix-removal-to-make-array-strictly-increasing/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n =nums.size();
        for(int i=n-1;i>0;i--){
            if(nums[i]<=nums[i-1]){
                return i;
            }
        }
        return 0;
    }
};
