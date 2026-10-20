/**
 * Problem: Find All Numbers Disappeared in an Array (448)
 * Link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>freq(nums.size()+1,0);
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        for(int i=1;i<=nums.size();i++){
            if(freq[i] ==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
