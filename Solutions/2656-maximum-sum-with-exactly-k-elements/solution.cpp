/**
 * Problem: Maximum Sum With Exactly K Elements  (2656)
 * Link: https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maximizeSum(vector<int>& nums, int k) {
        int count = 0;
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        while(count != k){
            ans += nums[n-1];
            nums[n-1] += 1;
            count++;
        }
        return ans;
    }
};
