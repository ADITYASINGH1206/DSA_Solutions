/**
 * Problem: Minimum String Length After Balanced Removals (3746)
 * Link: https://leetcode.com/problems/minimum-string-length-after-balanced-removals/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLengthAfterRemovals(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            while (!st.empty() and s[i] != st.top()) {
                if (i >= s.size()) break;
                st.pop();
                i++;
            }
            if (i < s.size())
            st.push(s[i]);
        }
        return st.size();
    }
};
