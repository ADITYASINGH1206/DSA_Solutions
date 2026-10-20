/**
 * Problem: Make The String Great (1544)
 * Link: https://leetcode.com/problems/make-the-string-great/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        int n = s.size();
        for(int i =0;i<n;i++){
            if(ans.empty()){
                ans.push_back(s[i]);
            }else{
                if(s[i] != ans.back() && tolower(s[i]) == tolower(ans.back())){
                    ans.pop_back();
                }else{
                    ans.push_back(s[i]);
                }
            }
        }
        return ans;
    }
};
