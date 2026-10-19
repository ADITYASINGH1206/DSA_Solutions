/**
 * Problem: Squares of a Sorted Array (977)
 * Link: https://leetcode.com/problems/squares-of-a-sorted-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0;
        int right = n - 1;
        
        for (int i = n - 1; i >= 0; i--) {
            int left_s = nums[left] * nums[left];
            int right_s = nums[right] * nums[right];
            
            if (left_s > right_s) {
                result[i] = left_s;
                left++; 
            } else {
                result[i] = right_s;
                right--; 
            }
        }
        
        return result;
    }
};
