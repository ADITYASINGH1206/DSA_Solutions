/**
 * Problem: Absolute Difference Between Maximum and Minimum K Elements (3774)
 * Link: https://leetcode.com/problems/absolute-difference-between-maximum-and-minimum-k-elements/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxi = 0;
        int mini = 0;
        int n = nums.size();
        for(int i = 0;i<k && i<n;i++){
            mini += nums[i];
        }

        for(int i = n-1;i>n-k-1 && i>=0;i--){
            maxi += nums[i];
        }

        return abs(maxi-mini);
    }
};
