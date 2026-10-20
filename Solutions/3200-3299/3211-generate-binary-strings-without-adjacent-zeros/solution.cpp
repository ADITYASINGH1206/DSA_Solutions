/**
 * Problem: Generate Binary Strings Without Adjacent Zeros (3211)
 * Link: https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void helper(string cur,int& n,vector<string>& result){
        if(cur.size() == n) {
            result.push_back(cur);
            return;
        } 

        if (cur.empty() || cur.back() == '1') {
            helper(cur + '0', n, result);
        }
        helper(cur+'1',n,result);
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        helper("",n,ans);
        return ans;
    }
};
