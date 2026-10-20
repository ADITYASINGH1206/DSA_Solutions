/**
 * Problem: Valid Binary Strings With Cost Limit (3955)
 * Link: https://leetcode.com/problems/valid-binary-strings-with-cost-limit/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int n,int k,int cost,string& cur,vector<string>& ans){
        if(cur.size() == n){
            if (cost <= k) ans.push_back(cur);
            return;
        }

        if(cur.size()==0){
            cur+='0';
            backtrack(n,k,cost,cur,ans);
            cur.pop_back();
            cur+='1';
            backtrack(n,k,cost,cur,ans);
            cur.pop_back();
        }
        else{
            if(cur.back() == '1'){
                cur+= '0';
                backtrack(n,k,cost,cur,ans);
                cur.pop_back();
            }else{
                cur+='0';
                backtrack(n,k,cost,cur,ans);
                cur.pop_back();
                cur+='1';
                cost+=cur.size()-1;
                backtrack(n,k,cost,cur,ans);
                cur.pop_back();
            }
        }

    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        string cur;
        backtrack(n,k,0,cur,ans);
        return ans;
    }
};
