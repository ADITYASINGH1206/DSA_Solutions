/**
 * Problem: Concatenate Array With Reverse (3925)
 * Link: https://leetcode.com/problems/concatenate-array-with-reverse/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n,0);

        for(int i = 0 ;i<n;i++){
            ans[i]= nums[i];
            ans[n+i] = nums[n-i-1];
        }
        return ans;
            
    }
};
