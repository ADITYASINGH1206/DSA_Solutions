/**
 * Problem: Daily Temperatures (739)
 * Link: https://leetcode.com/problems/daily-temperatures/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <int> stk;
        int n = temperatures.size();
        vector<int> ans(n);
        for(int i = n-1;i>-1;i--){
            while(!stk.empty() && temperatures[i] >= temperatures[stk.top()]){
                stk.pop();
            }
            if(!stk.empty()) ans[i] = stk.top()- i;
            else ans[i] = 0;
            stk.push(i);
        }
        return ans;
    }
};
