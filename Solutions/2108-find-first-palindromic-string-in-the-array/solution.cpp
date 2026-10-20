/**
 * Problem: Find First Palindromic String in the Array (2108)
 * Link: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(string word){
        int m = word.size();
        int l = 0;
        int r = m-1;
        while(l<r){
            if(word[l]!= word[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for(auto word : words){
            if(helper(word)) return word;
        }
        return "";
    }
};
