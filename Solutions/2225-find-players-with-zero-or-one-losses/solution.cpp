/**
 * Problem: Find Players With Zero or One Losses (2225)
 * Link: https://leetcode.com/problems/find-players-with-zero-or-one-losses/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> lossCount; 
        
        for(int i = 0; i < matches.size(); i++) {
            int winner = matches[i][0];
            int loser = matches[i][1];
            if(lossCount.find(winner) == lossCount.end()) {
                lossCount[winner] = 0;
            }
            lossCount[loser]++;
        }
        
        vector<int> zeroLoss;
        vector<int> oneLoss;
        for(auto it : lossCount) {
            if(it.second == 0) {
                zeroLoss.push_back(it.first);
            } else if(it.second == 1) {
                oneLoss.push_back(it.first);
            }
        }
        return {zeroLoss, oneLoss};
    }
};
