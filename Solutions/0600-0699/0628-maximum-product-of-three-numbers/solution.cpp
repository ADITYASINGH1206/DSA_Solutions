/**
 * Problem: Maximum Product of Three Numbers (628)
 * Link: https://leetcode.com/problems/maximum-product-of-three-numbers/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = INT_MIN;
        int n = nums.size();
        if(n==3){
            return ans = nums[0]*nums[1]*nums[2];
        } 
        for(int i = 0 ; i < n-2 ; i++){
            int n1 = nums[i];
            int n2 = nums[i+1];
            int n3 = nums[i+2];
            if(n1*n2 > 0){
                n3 = nums[n-1];
            }
            ans = max(ans,n1*n2*n3);
        }

        return ans;
    }
};
