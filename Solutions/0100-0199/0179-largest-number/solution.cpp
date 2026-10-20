/**
 * Problem: Largest Number (179)
 * Link: https://leetcode.com/problems/largest-number/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for (auto it : nums) {
            str.push_back(to_string(it));
        }

        sort(str.begin(), str.end(), [](string a , string b){
            return a+b > b+a ;
        });

        if (str[0] == "0") return "0";

        string ans = "";
        for (auto &s : str) {
            ans += s;
        }

        return ans;
    }
};
