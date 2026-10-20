/**
 * Problem: Binary Subarrays With Sum (930)
 * Link: https://leetcode.com/problems/binary-subarrays-with-sum/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atmost(vector<int>& nums, int goal) {
        int l=0,r=0,sum=0,cnt=0;
        if(goal<0) return 0;
        while(r<nums.size())
        {
            sum+=nums[r];
            while(sum>goal)
            {
                sum=sum-nums[l];
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
    return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};
