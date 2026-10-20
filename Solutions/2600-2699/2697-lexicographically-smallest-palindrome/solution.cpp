/**
 * Problem: Lexicographically Smallest Palindrome (2697)
 * Link: https://leetcode.com/problems/lexicographically-smallest-palindrome/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r= n-1;
        while(l<r){
            if(s[l] != s[r]){
                if(s[l]-'a' > s[r] - 'a'){
                    s[l] = s[r];
                }else{
                    s[r] = s[l];
                }
            }
            l++,r--;
        }

        return s;
    }
};
