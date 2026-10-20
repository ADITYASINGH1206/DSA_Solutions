/**
 * Problem: Smallest Index With Digit Sum Equal to Index (3550)
 * Link: https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int temp = nums[i];
            int sum = 0;
            while(temp){
                int digit = temp%10;
                sum += digit;
                temp/=10;
            }
            if(sum == i) return i;
        }
        return -1;
    }
};
