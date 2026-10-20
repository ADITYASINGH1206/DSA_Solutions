/**
 * Problem: Longest Balanced Substring II (3714)
 * Link: https://leetcode.com/problems/longest-balanced-substring-ii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        if (n == 0) return 0;
        int max_len = 0;
        int current_run = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && s[i] == s[i-1]) {
                current_run++;
            } else {
                current_run = 1;
            }
            max_len = max(max_len, current_run);
        }
        char pairs[3][3] = {
            {'a', 'b', 'c'},
            {'a', 'c', 'b'},
            {'b', 'c', 'a'}
        };

        for (auto& p : pairs) {
            char c1 = p[0];
            char c2 = p[1];
            char forbidden = p[2];

            unordered_map<int, int> mp;
            mp[0] = -1; 
            int balance = 0;

            for (int i = 0; i < n; ++i) {
                if (s[i] == forbidden) {
                    balance = 0;
                    mp.clear();
                    mp[0] = i; 
                } else {
                    if (s[i] == c1) balance++;
                    else if (s[i] == c2) balance--;
                    
                    if (mp.count(balance)) {
                        max_len = max(max_len, i - mp[balance]);
                    } else {
                        mp[balance] = i;
                    }
                }
            }
        }

        unordered_map<string, int> diff_map;
        diff_map["0#0"] = -1; 
        
        int ca = 0, cb = 0, cc = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') ca++;
            else if (s[i] == 'b') cb++;
            else if (s[i] == 'c') cc++;
            int d1 = ca - cb;
            int d2 = cb - cc;
            string key = to_string(d1) + "#" + to_string(d2);

            if (diff_map.count(key)) {
                max_len = max(max_len, i - diff_map[key]);
            } else {
                diff_map[key] = i;
            }
        }

        return max_len;
    }
};
