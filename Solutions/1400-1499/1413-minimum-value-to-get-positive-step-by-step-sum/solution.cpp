/**
 * Problem: Minimum Value to Get Positive Step by Step Sum (1413)
 * Link: https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int curr = 0;
        int minm = INT_MAX;
        for(int num:nums){
            curr+=num;
            minm=min(minm,curr);
        }
        return minm>0 ? 1:abs(minm)+1;      
    }
};
