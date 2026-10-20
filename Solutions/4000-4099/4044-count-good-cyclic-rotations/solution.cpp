/**
 * Problem: Count Good Cyclic Rotations (4044)
 * Link: https://leetcode.com/problems/count-good-cyclic-rotations/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        ll total = accumulate(nums.begin(),nums.end(),0LL);
        ll sum = 0;
        for(int i= 0;i<n/2;i++){
            sum+=nums[i];
        }
        int l =0;
        int r = n/2;
        for(int i=0;i<n;i++){
            sum+=nums[r%n];
            sum-=nums[l++];
            r++;
            if(sum>total-sum){
                ans++;
            }
        }
        return ans;
    }
};
