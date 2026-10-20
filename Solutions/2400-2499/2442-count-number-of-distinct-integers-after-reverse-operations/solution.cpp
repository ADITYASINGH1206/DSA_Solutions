/**
 * Problem: Count Number of Distinct Integers After Reverse Operations (2442)
 * Link: https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverse_digits(int num,vector<int>&nums){
        int temp = num;
        int new_num = 0;
        while(temp > 0){
            int digit = temp%10;
            new_num = (new_num * 10) + digit;
            temp /= 10;
        }
        nums.push_back(new_num);
    }
    int countDistinctIntegers(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            reverse_digits(nums[i],nums);
        }
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }
        for(auto& [key,value] : mp){
            ans++;
        }
        return ans;
    }
};
