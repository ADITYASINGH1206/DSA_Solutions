/**
 * Problem: Number of Strings That Appear as Substrings in Word (1967)
 * Link: https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        vector<string> sub;
        int n = word.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                string subs = word.substr(i,j-i+1);
                sub.push_back(subs);
            }
        }
        int n2 = patterns.size();
        int ans = 0;
        for(int i =0 ;i<n2;i++){
            string temp = patterns[i];
            for(int j = 0;j<sub.size();j++){
                if(patterns[i] == sub[j]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
