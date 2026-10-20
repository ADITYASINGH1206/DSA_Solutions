/**
 * Problem: Transformed Array (3379)
 * Link: https://leetcode.com/problems/transformed-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);\
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                int idx = (i + nums[i]) % n;
                ans[i] = nums[idx];
            }
            else if(nums[i] ==0){
                ans[i] = nums[i];
            }
            else{
                int idx = ((i - abs(nums[i])) % n + n) % n;
                ans[i] = nums[idx];
            }
        }
        return ans;
    }
};
