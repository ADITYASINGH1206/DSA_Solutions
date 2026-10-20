/**
 * Problem: Find if Digit Game Can Be Won (3232)
 * Link: https://leetcode.com/problems/find-if-digit-game-can-be-won/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int alice = 0;
        int bob = 0;
        for(int num : nums){
            if(num/10) bob += num;
            else alice += num;
        }
        return alice != bob;
    }
};
