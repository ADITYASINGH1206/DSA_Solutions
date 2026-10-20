/**
 * Problem: Summary Ranges (228)
 * Link: https://leetcode.com/problems/summary-ranges/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
    
        if (n == 0)
        return ans;
        int start = nums[0];

        for (int i = 0; i < n; i++) {
            if (i == n - 1 || nums[i + 1] != nums[i] + 1) {
                if (start != nums[i]) {
                    ans.push_back(to_string(start) + "->" + to_string(nums[i]));
                } 
                else {
                    ans.push_back(to_string(start));
                }
                if (i != n - 1) {
                    start = nums[i + 1];
                }
            }
        }
        return ans;
    }
};
