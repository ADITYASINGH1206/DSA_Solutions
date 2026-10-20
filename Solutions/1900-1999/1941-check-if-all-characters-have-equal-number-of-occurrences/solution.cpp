/**
 * Problem: Check if All Characters Have Equal Number of Occurrences (1941)
 * Link: https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int>freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        for(int i = 1 ;i<s.size();i++){
            if(freq[s[i]-'a']!=freq[s[i-1]-'a']){
                return false;
            }
        }
        return true;
    }
};
