/**
 * Problem: Minimum Operations to Make the Array Increasing (1827)
 * Link: https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 1;i<n;i++){
            if(nums[i] <= nums[i-1]){
                int temp = nums[i-1]+1;
                ans += abs(nums[i]-temp);
                nums[i] = temp;
            }
        }
        return ans;
    }
};
