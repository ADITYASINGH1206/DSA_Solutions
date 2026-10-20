/**
 * Problem: Remove All Occurrences of a Substring (1910)
 * Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string stk;
        int tn = part.size();
        char te = part.back();

        for (char c : s) {
            stk.push_back(c);

            if (c == te && stk.size() >= tn) {
                if (stk.substr(stk.size() - tn) == part) {
                    stk.erase(stk.size() - tn);
                }
            }
        }
        return stk;
    }
};
