/**
 * Problem: Reverse Substrings Between Each Pair of Parentheses (1190)
 * Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int n= s.size();
        string ans = "";
        stack<int> stk;
        for(int i = 0;i<n;i++){
            if(s[i] == '(') stk.push(ans.size());
            else if(s[i] == ')'){
                int temp = stk.top();
                stk.pop();
                reverse(ans.begin()+temp,ans.end());
            }else{
                ans += s[i];
            }
        }

        return ans;
    }
};
