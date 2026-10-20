/**
 * Problem: Minimum Number Game (2974)
 * Link: https://leetcode.com/problems/minimum-number-game/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n  = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i+=2){
            swap(nums[i],nums[i+1]);
        }
        return nums;
    }
};
