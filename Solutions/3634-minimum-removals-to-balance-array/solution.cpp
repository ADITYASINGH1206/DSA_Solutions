/**
 * Problem: Minimum Removals to Balance Array (3634)
 * Link: https://leetcode.com/problems/minimum-removals-to-balance-array/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();
        int l = 0;
        for(int r=0;r<nums.size();r++){
            while((long long)nums[r] > (long long)nums[l] *k){
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return n-ans;
    }
};
