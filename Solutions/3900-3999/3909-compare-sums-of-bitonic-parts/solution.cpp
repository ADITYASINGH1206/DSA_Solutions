/**
 * Problem: Compare Sums of Bitonic Parts (3909)
 * Link: https://leetcode.com/problems/compare-sums-of-bitonic-parts/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        int idx = 0;

        for(int i = 0;i<n;i++){
            if(nums[i] == maxi){
                idx = i;
                break;
            }
        }

        long long leftsum = 0;
        long long rightsum = 0;
        
        for(int i = 0;i<=idx;i++){
            leftsum += nums[i];
        }
        for(int i = idx;i<n;i++){
            rightsum += nums[i];
        }
        if(leftsum > rightsum) return 0;
        else if(rightsum > leftsum) return 1;
        else return -1;
    }
};
