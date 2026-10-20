/**
 * Problem: Count Number of Nice Subarrays (1248)
 * Link: https://leetcode.com/problems/count-number-of-nice-subarrays/
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
            sum+=(nums[r]%2);
            while(sum>goal)
            {
                sum=sum-(nums[l]%2);
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
    return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};
