/**
 * Problem: Sign of the Product of an Array (1822)
 * Link: https://leetcode.com/problems/sign-of-the-product-of-an-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int num : nums){
            if(num == 0) return 0;
            else if(num < 0) ans++;
        }
        if(ans%2 == 0) return 1;
        return -1;
    }
};
