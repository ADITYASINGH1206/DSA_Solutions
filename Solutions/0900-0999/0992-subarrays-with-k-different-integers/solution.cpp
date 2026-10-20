/**
 * Problem: Subarrays with K Different Integers (992)
 * Link: https://leetcode.com/problems/subarrays-with-k-different-integers/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int sub = sub_atmost_k(nums,k);
        int sub1 = sub_atmost_k(nums,k-1);
        return (sub - sub1);
    }
    int sub_atmost_k(vector<int>& nums,int k){
        unordered_map<int,int> map;
        int left = 0 , right = 0,ans = 0;
        while(right<nums.size()){
            map[nums[right]]++;
            while(map.size()>k){
                map[nums[left]]--;
                if(map[nums[left]]==0)map.erase(nums[left]);
                left++;
            }
            ans += right-left+1;
            right++;
        }
        return ans;
    }
};
