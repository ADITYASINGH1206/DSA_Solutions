/**
 * Problem: Count Integers Appearing in a Single Block (4038)
 * Link: https://leetcode.com/problems/count-integers-appearing-in-a-single-block/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> mp;

        int n = nums.size();

        mp[nums[0]] = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i - 1]){
                mp[nums[i]]++;
            }
        }

        int cnt = 0;

        for(auto &p : mp){
            if(p.second == 1){
                cnt++;
            }
        }

        return cnt;
    }
};
