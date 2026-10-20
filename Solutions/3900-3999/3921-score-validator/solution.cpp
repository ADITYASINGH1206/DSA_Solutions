/**
 * Problem: Score Validator (3921)
 * Link: https://leetcode.com/problems/score-validator/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        vector<int> ans{0,0};
        int n = events.size();
        for(int i = 0;i<n;i++){
            string temp = events[i];
            if(events[i] == "W") ans[1]++;
            else if(events[i] == "WD") ans[0]++;
            else if(events[i] == "NB") ans[0]++;
            else{
                int run = stoi(temp);
                ans[0] += run;
            }
            if(ans[1] == 10)return ans;
        }
        return ans;
    }
};
