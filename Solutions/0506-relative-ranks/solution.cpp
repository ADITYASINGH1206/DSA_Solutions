/**
 * Problem: Relative Ranks (506)
 * Link: https://leetcode.com/problems/relative-ranks/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sortedScore = score;
        sort(sortedScore.rbegin(), sortedScore.rend());
        unordered_map<int, string> rankMap;
        
        for(int i = 0; i < sortedScore.size(); i++) {
            if (i == 0) {
                rankMap[sortedScore[i]] = "Gold Medal";
            } else if (i == 1) {
                rankMap[sortedScore[i]] = "Silver Medal";
            } else if (i == 2) {
                rankMap[sortedScore[i]] = "Bronze Medal";
            } else {
                rankMap[sortedScore[i]] = to_string(i + 1);
            }
        }
        vector<string> ans;
        for(int i = 0; i < score.size(); i++) {
            ans.push_back(rankMap[score[i]]);
        }
        
        return ans;
    }
};
