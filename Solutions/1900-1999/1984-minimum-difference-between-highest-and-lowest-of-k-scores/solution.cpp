/**
 * Problem: Minimum Difference Between Highest and Lowest of K Scores (1984)
 * Link: https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = k-1;
        while(r<n){
            ans = min(ans,nums[r]-nums[l]);
            r++,l++;
        }
        return ans;
    }
};
