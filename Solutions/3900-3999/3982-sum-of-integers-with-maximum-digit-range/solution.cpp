/**
 * Problem: Sum of Integers with Maximum Digit Range (3982)
 * Link: https://leetcode.com/problems/sum-of-integers-with-maximum-digit-range/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int maxi =  0;
        for(int i = 0;i<n;i++){
            int temp = nums[i];
            int m1 = 0;
            int s1 = INT_MAX;
            int dif = 0;
            while(temp){
                int digit = temp%10;
                if(digit > m1) m1 = digit;
                if(digit < s1) s1 = digit;
                temp/=10;
            }
            dif = m1-s1;
            if(dif>maxi){
                maxi = dif;
                ans = nums[i];
            }
            else if(dif == maxi){
                ans += nums[i];
            }
        }
        return ans;
    }
};
