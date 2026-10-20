/**
 * Problem: Count Equal and Divisible Pairs in an Array (2176)
 * Link: https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        if(n == 1) return 0;
        for(int i =0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int r = i*j;
                if(nums[i] == nums[j] && r%k ==0) ans++;
            }
        }
        return ans;

    }
};
