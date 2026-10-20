/**
 * Problem: Subarrays Distinct Element Sum of Squares I (2913)
 * Link: https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i =0;i<n;i++){
            vector<bool> dis(101,false);
            int count = 0;
            for(int j = i;j<n;j++){
                if(!dis[nums[j]]){
                    count++;
                    dis[nums[j]] = true;
                }
                ans += count*count;
            }
        }
        return ans;
    }
};
