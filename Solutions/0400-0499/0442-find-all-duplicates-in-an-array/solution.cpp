/**
 * Problem: Find All Duplicates in an Array (442)
 * Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int num:nums){
            if(mp[num]) ans.push_back(num);
            else{
                mp[num]++;
            }
        }

        return ans;
    }
};
