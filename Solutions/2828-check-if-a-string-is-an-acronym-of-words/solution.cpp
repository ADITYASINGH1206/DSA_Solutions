/**
 * Problem: Check if a String Is an Acronym of Words (2828)
 * Link: https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string res = "";
        int n = words.size();
        for(auto & word:words){
            res += word[0];
        }
        
        return res == s;
    }
};
