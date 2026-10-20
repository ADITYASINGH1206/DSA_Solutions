/**
 * Problem: Minimum Moves to Equal Array Elements III (3736)
 * Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int ans = 0;
        for(int num:nums){
            ans += abs(num-maxi);
        }
        return ans;

    }
};
