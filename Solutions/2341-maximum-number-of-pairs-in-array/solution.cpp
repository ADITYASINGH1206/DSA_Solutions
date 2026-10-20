/**
 * Problem: Maximum Number of Pairs in Array (2341)
 * Link: https://leetcode.com/problems/maximum-number-of-pairs-in-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans = {0,n};
        unordered_map<int,int> mp;
        for(auto x: nums){
            mp[x]++;
        }
    
        for(auto it: mp){
            if(it.second>=2){
                ans[0]+= it.second/2;
                ans[1] -= (it.second/2)*2;
            }
        }
        return ans;
    }
};
