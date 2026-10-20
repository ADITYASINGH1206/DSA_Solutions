/**
 * Problem: Longest Resilient Subarray I (4075)
 * Link: https://leetcode.com/problems/longest-resilient-subarray-i/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int ans = 1;
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int st = i;
            long long m = nums[i] % k;
            while (i < n && nums[i] % k == m) {
                i++;
            }
            int len = i - st;
            for (int j= len; j>= 1; j--) {
                if (((j- 1) * m) % k == 0) {
                    if (j> ans) {
                        ans = j;
                    }
                    break; 
                }
            }
        }
        
        return ans;
    }
};
