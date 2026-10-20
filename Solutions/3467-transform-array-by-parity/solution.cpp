/**
 * Problem: Transform Array by Parity (3467)
 * Link: https://leetcode.com/problems/transform-array-by-parity/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int>ans;
        for(int i =0;i<nums.size();i++){
            if(nums[i]%2==0){
                ans.push_back(0);
            }
        }
        for(int i =ans.size();i<nums.size();i++){
            ans.push_back(1);
        }
        return ans;
    }
};
