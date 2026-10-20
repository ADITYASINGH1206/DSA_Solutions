/**
 * Problem: Majority Element II (229)
 * Link: https://leetcode.com/problems/majority-element-ii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1 = -1, num2 = -2; 
        int c1 = 0, c2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == num1) {
                c1++;
            } else if (nums[i] == num2) {
                c2++;
            } else if (c1 == 0) {
                num1 = nums[i];
                c1 = 1;
            } else if (c2 == 0) {
                num2 = nums[i];
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }

        int count1 = 0;
        int count2 = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == num1) count1++;
            else if (nums[i] == num2) count2++;
        }

        vector<int> ans;
        int threshold = n / 3;
        
        if (count1 > threshold) ans.push_back(num1);
        if (count2 > threshold) ans.push_back(num2);
        
        return ans;
    }
};
