/**
 * Problem: Split With Minimum Sum (2578)
 * Link: https://leetcode.com/problems/split-with-minimum-sum/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        
        string num1 = "";
        string num2 = "";
        for(int i = 0; i < s.size(); i++) {
            if(i % 2 == 0) {
                num1 += s[i];
            } else {
                num2 += s[i];
            }
        }
        return stoi(num1) + stoi(num2);
    }
};
