/**
 * Problem: Sort Vowels in a String (2785)
 * Link: https://leetcode.com/problems/sort-vowels-in-a-string/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkVowel(char ch){
        char vowel[10]= {'a','e','i','o','u','A','E','I','O','U'};
        for(char c:vowel){
            if(c==ch) return true;
        }
        return false;
    }

    string sortVowels(string s) {
        vector<char> vow;
        for(char c:s){
            if(checkVowel(c)) vow.push_back(c);
        }
        sort(vow.begin(),vow.end());
        int idx = 0;
        for(char &c:s){
            if(checkVowel(c)){
                c = vow[idx++];
            }
        }
        return s;
    }
};
