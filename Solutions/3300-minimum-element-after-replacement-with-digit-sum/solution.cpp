/**
 * Problem: Minimum Element After Replacement With Digit Sum (3300)
 * Link: https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(int num : nums){
            int temp = num;
            int sum = 0;
            while(temp){
                int digit = temp%10;
                sum+= digit;
                temp/=10;
            }
            if(sum < ans) ans = sum;
        }
        return ans;

    }
};
