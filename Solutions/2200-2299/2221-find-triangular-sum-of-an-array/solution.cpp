/**
 * Problem: Find Triangular Sum of an Array (2221)
 * Link: https://leetcode.com/problems/find-triangular-sum-of-an-array/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while(n>1){
            for(int i = 0;i<n-1;i++){
                nums[i] = (nums[i] + nums[i+1])%10;
            }
            n--;
        }
        return nums[0];
    }
    
};
