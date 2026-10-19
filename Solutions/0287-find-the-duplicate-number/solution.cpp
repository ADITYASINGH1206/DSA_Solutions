/**
 * Problem: Find the Duplicate Number (287)
 * Link: https://leetcode.com/problems/find-the-duplicate-number/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];
        
        do {
            slow = nums[slow];               
            fast = nums[nums[fast]];       
        } while (slow != fast);
        
        slow = nums[0];                      
        
        while (slow != fast) {
            slow = nums[slow];               
            fast = nums[fast];              
        }
        
        return slow;
    }
};
