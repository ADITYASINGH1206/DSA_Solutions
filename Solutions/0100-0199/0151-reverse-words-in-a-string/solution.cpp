/**
 * Problem: Reverse Words in a String (151)
 * Link: https://leetcode.com/problems/reverse-words-in-a-string/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        vector<string> s1;
        int n = s.size();
        int i = n - 1;
        
        while(i >= 0) {
            while(i >= 0 && s[i] == ' ') {
                i--;
            }
            if (i < 0) break; 
            string temp = "";
            while(i >= 0 && s[i] != ' '){
                temp += s[i];
                i--;
            }
            reverse(temp.begin(), temp.end());
            s1.push_back(temp);
        }
        
        for(int j = 0; j < s1.size(); j++){
            ans += s1[j];
            if(j != s1.size() - 1) ans += ' ';
        }
        
        return ans;
    }
};
