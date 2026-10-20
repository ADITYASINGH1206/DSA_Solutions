/**
 * Problem: Minimum Remove to Make Valid Parentheses (1249)
 * Link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(std::string s) {
        int left = 0;
        int right = 0;
        stack<char> stk;

        for (char ch : s) {
            if (ch == '(') {
                left++;
            } else if (ch == ')') {
                right++;
            }
            if (right > left) {
                right--;
                continue;
            } else {
                stk.push(ch);
            }
        }

        string ans = "";
        
        while (!stk.empty()) {
            char curr = stk.top();
            stk.pop();
            if (left > right && curr == '(') {
                left--;
            } else {
                ans += curr;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
