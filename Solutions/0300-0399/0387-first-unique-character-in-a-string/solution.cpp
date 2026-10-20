/**
 * Problem: First Unique Character in a String (387)
 * Link: https://leetcode.com/problems/first-unique-character-in-a-string/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> hash(26,0);
        for(char c:s){
            hash[c-'a']++;
        }
        for(int i =0;i<s.size();i++){
            if(hash[s[i]-'a']== 1){
                return i;
            }
        }
        return -1;
    }
};
