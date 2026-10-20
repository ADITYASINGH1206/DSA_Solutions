/**
 * Problem: Minimum Add to Make Parentheses Valid (921)
 * Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int n = s.size();
        vector<char> stk;
        for(int i =0;i<n;i++){
            if(stk.empty()){
                stk.push_back(s[i]);
            }else{
                if(stk.back() == '(' && s[i] == ')') stk.pop_back();
                else stk.push_back(s[i]);
            }
        }
        ans = stk.size();
        return ans;
    }
};
