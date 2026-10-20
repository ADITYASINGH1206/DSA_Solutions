/**
 * Problem: The k-th Lexicographical String of All Happy Strings of Length n (1415)
 * Link: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> ans;
        string s = "";
        auto dfs = [&](this auto&& dfs) -> void {
            if (s.size() == n) {
                ans.emplace_back(s);
                return;
            }
            if (ans.size() >= k) {
                return;
            }
            for (char c = 'a'; c <= 'c'; ++c) {
                if (s.empty() || s.back() != c) {
                    s.push_back(c);
                    dfs();
                    s.pop_back();
                }
            }
        };
        dfs();
        return ans.size() < k ? "" : ans[k - 1];
    }
};
