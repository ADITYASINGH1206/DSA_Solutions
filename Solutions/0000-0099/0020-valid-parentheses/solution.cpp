/**
 * Problem: Valid Parentheses (20)
 * Link: https://leetcode.com/problems/valid-parentheses/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> stk;
        for(int i = 0;i<n;i++){
            if(stk.empty()){
                stk.push(s[i]);
            }else{
                if(stk.top() == '(' && s[i] == ')') stk.pop(); 
                else if(stk.top() == '[' && s[i] == ']') stk.pop(); 
                else if(stk.top() == '{' && s[i] == '}') stk.pop(); 
                else stk.push(s[i]);
            }
        }

        bool ans = stk.size() == 0 ? true : false;

        return ans;
    }
};
