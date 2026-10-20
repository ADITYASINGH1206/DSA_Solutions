/**
 * Problem: Monotonic Array (896)
 * Link: https://leetcode.com/problems/monotonic-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int change = 0; 
        
        for(int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) { 
                if (change == -1) return false;
                change = 1;
            } 
            else if (nums[i] < nums[i-1]) {
                if (change == 1) return false;
                change = -1;
            }
        }
        
        return true;
    }
};
