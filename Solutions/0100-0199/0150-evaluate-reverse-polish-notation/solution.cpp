/**
 * Problem: Evaluate Reverse Polish Notation (150)
 * Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        stack<int> stk;
        int n = tokens.size();
        for(int i =0;i<n;i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int c = 0;
                if(tokens[i] == "+") c = b+a;
                else if(tokens[i] == "*") c = b*a;
                else if(tokens[i] == "-") c = b-a;
                else if(tokens[i] == "/") c = b/a;
                stk.push(c);
            }
            else{
                int temp = stoi(tokens[i]);
                stk.push(temp);
            }
        }
        return stk.top();
    }
};
