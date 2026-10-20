/**
 * Problem: Baseball Game (682)
 * Link: https://leetcode.com/problems/baseball-game/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        int ans = 0;
        vector<int> scores;
        int n = operations.size();
        for(int i = 0;i < n;i++){
            if(operations[i] == "+"){
                int temp = scores[scores.size()-1] + scores[scores.size()-2];
                scores.push_back(temp);
            }else if(operations[i] == "C"){
                scores.pop_back();
            }else if(operations[i] == "D"){
                int temp = 2*(scores.back());
                scores.push_back(temp);
            }else{
                scores.push_back(stoi(operations[i]));
            }
        }
        ans = accumulate(scores.begin(),scores.end(),0);

        return ans;
    }
};
