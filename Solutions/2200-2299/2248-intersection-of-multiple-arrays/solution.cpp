/**
 * Problem: Intersection of Multiple Arrays (2248)
 * Link: https://leetcode.com/problems/intersection-of-multiple-arrays/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int>ans;
        vector<int>freq(1001,0);
        int n = nums.size();
        for(vector v:nums){
            for(int num : v){
                freq[num]++;
            }
        }
        for(int i = 0;i<1001;i++){
            if(freq[i]==n){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
