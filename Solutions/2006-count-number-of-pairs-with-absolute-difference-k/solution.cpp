/**
 * Problem: Count Number of Pairs With Absolute Difference K (2006)
 * Link: https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(nums[i] - nums[j])==k) ans++;
            }
        }
        return ans;
    }
};
