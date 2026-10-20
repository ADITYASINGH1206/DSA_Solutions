/**
 * Problem: Uncommon Words from Two Sentences (884)
 * Link: https://leetcode.com/problems/uncommon-words-from-two-sentences/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp;
        vector<string> ans;
        string temp = "";
        for(char c: s1){
            if(c == ' ') {
                mp[temp]++;
                temp = "";
            }else{
                temp += c;
            }
        }
        mp[temp]++;
        temp = "";
        for(char c: s2){
            if(c == ' ') {
                mp[temp]++;
                temp = "";
            }else{
                temp += c;
            }
        }
        mp[temp]++;
        for(auto [key,value] : mp){
            if (value == 1){
                ans.push_back(key);
            }
        }
        return ans;


    }
};
