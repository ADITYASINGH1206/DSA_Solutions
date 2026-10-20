/**
 * Problem: Separate the Digits in an Array (2553)
 * Link: https://leetcode.com/problems/separate-the-digits-in-an-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int num : nums){
            string temp = to_string(num);
            for(char c: temp){
                ans.push_back(c-'0');
            }
        }
        return ans;
    }
};
