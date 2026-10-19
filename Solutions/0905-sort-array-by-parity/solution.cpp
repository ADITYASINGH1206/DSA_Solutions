/**
 * Problem: Sort Array By Parity (905)
 * Link: https://leetcode.com/problems/sort-array-by-parity/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i = 0 , j=0;
        for(;i<n;i++){
            if(nums[i]%2 == 0) swap(nums[j++],nums[i]);
        }

        return nums;
    }
};
