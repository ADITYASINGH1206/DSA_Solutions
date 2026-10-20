/**
 * Problem: Merge Strings Alternately (1768)
 * Link: https://leetcode.com/problems/merge-strings-alternately/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int l = 0;
        int r = 0;
        int m = word1.size();
        int n = word2.size();
        while(l<=r && l < m && r < n){
            ans += word1[l];
            ans += word2[r];
            l++;
            r++;
        }
        while(l < m){
            ans += word1[l];
            l++;
        }
        while(r < n){
            ans+= word2[r];
            r++;
        }

        return ans;
    }
};
