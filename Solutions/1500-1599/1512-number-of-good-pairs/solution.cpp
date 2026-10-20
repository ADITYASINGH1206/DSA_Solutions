/**
 * Problem: Number of Good Pairs (1512)
 * Link: https://leetcode.com/problems/number-of-good-pairs/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    ans++;
                }
            }
        }
        return ans-nums.size();
    }
};
