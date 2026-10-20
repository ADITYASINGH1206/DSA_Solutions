/**
 * Problem: Maximum Product of Two Elements in an Array (1464)
 * Link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi1 = INT_MIN;
        int maxi2 = INT_MIN;
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(nums[i]>maxi1){
                maxi2 = maxi1;
                maxi1 = nums[i];
            }else if(nums[i] > maxi2){
                maxi2 = nums[i];
            }
        }

        return (maxi1-1)*(maxi2-1);
    }
};
