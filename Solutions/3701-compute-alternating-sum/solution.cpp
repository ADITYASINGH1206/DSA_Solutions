/**
 * Problem: Compute Alternating Sum (3701)
 * Link: https://leetcode.com/problems/compute-alternating-sum/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int ans= 0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                ans+=nums[i];
            }
            else{
                ans-=nums[i];
            }
        }
        return ans;
    }
};
