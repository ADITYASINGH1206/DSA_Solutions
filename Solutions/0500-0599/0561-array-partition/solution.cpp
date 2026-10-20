/**
 * Problem: Array Partition (561)
 * Link: https://leetcode.com/problems/array-partition/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i+=2){
            ans+=min(nums[i],nums[i+1]);
        }
        return ans;
    }
};
