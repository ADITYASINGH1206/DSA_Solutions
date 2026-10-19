/**
 * Problem: N-Repeated Element in Size 2N Array (961)
 * Link: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int n = nums.size();
        int ans = 0;
        for(int num:nums){
            if(count == (n/2)) break;
            if(num == ans){
                count++;
            }else{
                ans = num;
                count = 1;
            }
        }
        return ans;
    }
};
