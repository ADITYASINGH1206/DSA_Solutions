/**
 * Problem: Max Consecutive Ones III (1004)
 * Link: https://leetcode.com/problems/max-consecutive-ones-iii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r<n){
            if(nums[r] == 0){
                count++;
                while(count>k){
                    if(nums[l] ==0){
                        count--;
                    }
                    l++;
                }
            }
            ans = max(ans,r-l+1);
            r++;
        
        }
        return ans;
    }
};
