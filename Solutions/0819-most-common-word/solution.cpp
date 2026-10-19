/**
 * Problem: Most Common Word (819)
 * Link: https://leetcode.com/problems/most-common-word/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> mp;
        set<string> st(banned.begin(),banned.end());
        string word = "";
        for(char c:paragraph){
            if(isalpha(c)) word+= tolower(c);
            else{
                if(!word.empty() && st.find(word) == st.end()) mp[word]++;
                word.clear();
            }
        }

        if(!word.empty() && st.find(word) == st.end()) mp[word]++;
        
        int maxi = 0;
        string ans = "";
        for(auto it:mp){
            if(it.second > maxi){
                ans = it.first;
                maxi = it.second;
            }
        }
        return ans;
    }
};
