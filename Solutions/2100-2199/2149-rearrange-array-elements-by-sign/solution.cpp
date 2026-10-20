/**
 * Problem: Rearrange Array Elements by Sign (2149)
 * Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int pos = 0;
        int neg =1;
        for(int i =0;i<nums.size();i++){
            if(nums[i]<0){
                ans[neg] = nums[i];
                neg+=2;
            }
            else{
                ans[pos] = nums[i];
                pos+=2;
            }
        }
        return ans;
    }
};
