/**
 * Problem: Longest Unequal Adjacent Groups Subsequence I (2900)
 * Link: https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string> ans;
        ans.push_back(words[0]);
        for(int i = 1;i<n;i++){
            if(groups[i] != groups[i-1]){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
