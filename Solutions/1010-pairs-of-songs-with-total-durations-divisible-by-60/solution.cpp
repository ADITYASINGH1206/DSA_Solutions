/**
 * Problem: Pairs of Songs With Total Durations Divisible by 60 (1010)
 * Link: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>count;
        int ans =0;
        for(int t:time){
            int song = t%60;
            int required = (60-song)%60;
            ans+=count[required];
            count[song]++;
        }
        return ans;
    }
};
