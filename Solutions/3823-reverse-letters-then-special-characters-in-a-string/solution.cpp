/**
 * Problem: Reverse Letters Then Special Characters in a String (3823)
 * Link: https://leetcode.com/problems/reverse-letters-then-special-characters-in-a-string/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseByType(string s) {
        string ans = "";
        vector<char> letters;
        vector<char> specials;
        for(char c: s){
            if(islower(c)){
                letters.push_back(c);
            }else{
                specials.push_back(c);
            }
        }
        int l = letters.size()-1;
        int r = specials.size()-1;

        for(char c:s){
            if(islower(c)){
                ans+= letters[l--];
            }else{
                ans+= specials[r--];
            }
        }
        return ans;
    }
};
