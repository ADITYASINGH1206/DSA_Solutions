/**
 * Problem: Letter Case Permutation (784)
 * Link: https://leetcode.com/problems/letter-case-permutation/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int i,string& s,string& cur,vector<string>& ans){
        if(cur.size() == s.size()){
            ans.push_back(cur);
            return;
        }
        

        if(isalpha(s[i])){
            cur+= tolower(s[i]);
            backtrack(i+1,s,cur,ans);
            cur.pop_back();
            cur+=toupper(s[i]);
            backtrack(i+1,s,cur,ans);
            cur.pop_back();
        }else{
            cur+= s[i];
            backtrack(i+1,s,cur,ans);
            cur.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string cur;
        backtrack(0,s,cur,ans);
        return ans;
    }
};
