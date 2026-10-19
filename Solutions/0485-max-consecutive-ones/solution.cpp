/**
 * Problem: Max Consecutive Ones (485)
 * Link: https://leetcode.com/problems/max-consecutive-ones/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                mx++;
                ans = max(ans,mx);
            }else{
                mx = 0;
            }
        }
        return ans;
    }
};
