/**
 * Problem: Count Dominant Indices (3833)
 * Link: https://leetcode.com/problems/count-dominant-indices/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return 0;

        int ans = 0;
        int sum = nums[n-1];
        int count = 1;
        
        for(int i =n-2;i>=0;i--){
            if(nums[i] * count >  sum){
                ans++;
            }
            sum+= nums[i];
            count++;
        }
        return ans;
        
    }
};
