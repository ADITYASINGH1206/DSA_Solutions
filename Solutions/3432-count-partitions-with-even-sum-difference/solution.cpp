/**
 * Problem: Count Partitions with Even Sum Difference (3432)
 * Link: https://leetcode.com/problems/count-partitions-with-even-sum-difference/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
    
        int rsum = accumulate(nums.begin(), nums.end(), 0);
        int lsum = 0;
        int ans = 0;
        
        for(int i = 0; i < n - 1; i++){
            lsum += nums[i];       
            rsum -= nums[i];       
            if((lsum - rsum) % 2 == 0) {
                ans++;
            }
        }
        
        return ans;
    }
};
