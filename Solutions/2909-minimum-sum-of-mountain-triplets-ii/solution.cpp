/**
 * Problem: Minimum Sum of Mountain Triplets II (2909)
 * Link: https://leetcode.com/problems/minimum-sum-of-mountain-triplets-ii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> left(n,0),right(n,0);
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        for(int i = 1;i<n;i++){
            left[i] = min(left[i-1],nums[i]);
        }
        for(int i = n-2;i>=0;i--){
            right[i] = min(right[i+1],nums[i]);
        }
        for(int i = 1;i<n-1;i++){
            if(nums[i]>left[i-1] && nums[i]>right[i+1]){
                ans = min(ans,nums[i]+left[i-1]+right[i+1]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
