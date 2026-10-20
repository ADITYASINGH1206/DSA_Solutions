/**
 * Problem: Rotate Non Negative Elements (3819)
 * Link: https://leetcode.com/problems/rotate-non-negative-elements/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> temp;
        for (int x : nums) {
            if (x >= 0) temp.push_back(x);
        }
        
        int m = temp.size();
        if (m == 0) return nums;
    
        k %= m;
        rotate(temp.begin(), temp.begin() +k, temp.end());
        int temp_idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                nums[i] = temp[temp_idx++];
            }
        }
        
        return nums;
    }
};
