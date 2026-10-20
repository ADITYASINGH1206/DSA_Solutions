/**
 * Problem: Construct Smallest Number From DI String (2375)
 * Link: https://leetcode.com/problems/construct-smallest-number-from-di-string/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        string ans = "";
        stack<int> st;
        int n = pattern.size();
        
        for (int i = 1; i <= n + 1; i++) {
            st.push(i);
            if (i == n + 1 || pattern[i - 1] == 'I') {
                while (!st.empty()) {
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }
        
        return ans;
    }
};
