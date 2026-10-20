/**
 * Problem: Difference Between Element Sum and Digit Sum of an Array (2535)
 * Link: https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int n){
        int t = n;
        int digitSum = 0;
        while(t>0){
            digitSum += t%10;
            t/=10;
        }
        return digitSum;
    }
    int differenceOfSum(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int digits = 0;
        for(int i = 0;i<nums.size();i++){
            digits += helper(nums[i]);
        }
        return abs(sum-digits);
    }
};
