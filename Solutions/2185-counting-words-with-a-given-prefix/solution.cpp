/**
 * Problem: Counting Words With a Given Prefix (2185)
 * Link: https://leetcode.com/problems/counting-words-with-a-given-prefix/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        int n = pref.size();
        for(auto& word:words){
            string sub = word.substr(0,n);
            if(sub == pref) ans++;
        }
        return ans;
    }
};
