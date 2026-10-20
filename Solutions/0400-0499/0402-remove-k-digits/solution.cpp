/**
 * Problem: Remove K Digits (402)
 * Link: https://leetcode.com/problems/remove-k-digits/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        int n = num.size();
        int count = 0;
        for (char c : num) {
            if (ans.empty()) {
                ans += c;
            } else {
                while (!ans.empty() && count < k && ans.back() > c) {
                    ans.pop_back();
                    count++;
                }
                ans.push_back(c);
            }

        }
        while (count < k && !ans.empty()) {
            ans.pop_back();
            count++;
        }
        size_t first_nonzero = ans.find_first_not_of('0');
        if (first_nonzero == string::npos) {
            return "0";
        }
        return ans.substr(first_nonzero);
    }
};
