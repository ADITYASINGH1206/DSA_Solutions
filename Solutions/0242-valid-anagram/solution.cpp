/**
 * Problem: Valid Anagram (242)
 * Link: https://leetcode.com/problems/valid-anagram/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> ch(26,0);
        int n = s.size();
        int r = t.size();
        if(n != r) return false;
        for(int i =0;i<n;i++){
            ch[s[i]-'a']++;
        }        
        for(int i =0;i<r;i++){
            ch[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(ch[i] != 0){
                return false;
            }
        }
        return true;
    
    }
};
