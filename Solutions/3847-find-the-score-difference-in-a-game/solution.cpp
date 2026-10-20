/**
 * Problem: Find the Score Difference in a Game (3847)
 * Link: https://leetcode.com/problems/find-the-score-difference-in-a-game/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        vector<int> playerScores(2, 0);
        int activeIdx = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 != 0) {
                activeIdx = 1 - activeIdx; 
            }
            if ((i + 1) % 6 == 0) {
                activeIdx = 1 - activeIdx;
            }
            playerScores[activeIdx] += nums[i];
        }

        return playerScores[0] - playerScores[1];
    }
};
