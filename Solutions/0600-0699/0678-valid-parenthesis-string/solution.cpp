/**
 * Problem: Valid Parenthesis String (678)
 * Link: https://leetcode.com/problems/valid-parenthesis-string/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int min = 0;
        int max = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                min++, max++;
            } else if (s[i] == ')') {
                min--, max--;
            } else {
                min--;
                max++;
            }
            if (min < 0)
                min = 0;
            if (max < 0)
                return false;
        }
        return (min == 0);
    }
};
