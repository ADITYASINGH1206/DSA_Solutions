/**
 * Problem: Left and Right Sum Differences (2574)
 * Link: https://leetcode.com/problems/left-and-right-sum-differences/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans;
        int leftsum =0;
        int rightsum =0;
        for(int i=0;i<nums.size();i++){
            rightsum+=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            rightsum-=nums[i];
            int dif = abs(leftsum-rightsum);
            ans.push_back(dif);
            leftsum+=nums[i];
        }
        return ans;
    }
};
