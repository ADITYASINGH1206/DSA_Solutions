/**
 * Problem: First Unique Even Element (3866)
 * Link: https://leetcode.com/problems/first-unique-even-element/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int>freq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        for(int x : nums) {
            if(x % 2 == 0 && freq[x] == 1) {
                return x;
            }
        }
        return -1;
    }
};
