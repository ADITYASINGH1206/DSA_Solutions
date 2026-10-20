/**
 * Problem: The Two Sneaky Numbers of Digitville (3289)
 * Link: https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        vector<int>freq(100,0);
        for(int x:nums){
            if(++freq[x] == 2){
                ans.push_back(x);
            }
        }
        return ans;

    }
};
