/**
 * Problem: Jump Game (55)
 * Link: https://leetcode.com/problems/jump-game/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

//Memo
class Solution {
public:
    bool recurse(vector<int>& nums, int index, vector<int>& memo) {
        if (index >= nums.size() - 1) return true;

        if (memo[index] != -1) {
            return memo[index] == 1;
        }

        int power = nums[index];
        int furthestJump = min((int)nums.size() - 1, index + power);

        for (int nextIndex = furthestJump; nextIndex > index; nextIndex--) {
            if (recurse(nums, nextIndex, memo)) {
                memo[index] = 1;
                return true;
            }
        }
        
        memo[index] = 0;
        return false;
    }

    bool canJump(vector<int>& nums) {
        // Initialize memo array with -1 (unvisited)
        vector<int> memo(nums.size(), -1);
        return recurse(nums, 0, memo);
    }
};
//Recursive
// class Solution {
// public:
//     bool recurse(vector<int>& nums,int index){
//         if(index>=nums.size()-1) return true;

//         int power = nums[index];


//         return false;
//     }
//     bool canJump(vector<int>& nums) {
//         return recurse(nums,0);
//     }
// };
