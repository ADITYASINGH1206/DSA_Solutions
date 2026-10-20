/**
 * Problem: Find Numbers with Even Number of Digits (1295)
 * Link: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int num:nums){
            int temp = num;
            int digits = 0;
            while(temp){
                digits++;
                temp/=10;
            }
            if(digits%2 ==0) ans++;
        }
        return ans;
    }
};
