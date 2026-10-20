/**
 * Problem: Shortest Completing Word (748)
 * Link: https://leetcode.com/problems/shortest-completing-word/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char,int> ls;
        for(char c:licensePlate){
            if(isalpha(c)){
                ls[tolower(c)]++;
            } 
        }
        int mini = INT_MAX;
        string ans = "";
        for(auto& word : words){
            shortestWord(ls,word,ans,mini);
        }
        return ans;
    }

    void shortestWord(unordered_map<char,int> ls,string word,string& ans,int& mini){
        int length = word.size();
        for(char c:word){
            if(ls.count(c) && ls[c]>0){
                ls[c]--;
                if(ls[c] == 0) ls.erase(c);
            }
        }
        if(ls.empty() && length < mini){
            mini = length;
            ans = word;
        }
    }
};
