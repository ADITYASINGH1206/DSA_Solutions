/**
 * Problem: Unique Middle Element (3978)
 * Link: https://leetcode.com/problems/unique-middle-element/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;         
        int target = nums[mid];   
        int count = 0;
        
        for (int num : nums) {
            if (num == target) {
                count++;
            }
            if (count > 1) {
                return false; 
            }
        }
        
        return count == 1;
    }
};
