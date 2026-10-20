/**
 * Problem: Delete Operation for Two Strings (583)
 * Link: https://leetcode.com/problems/delete-operation-for-two-strings/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
        if(i == 0 || j ==0)return 0;
        
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i-1]==s2[j-1]) return dp[i][j] = 1 + f(i-1,j-1,s1,s2,dp);

        return dp[i][j] = max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        int lcs = f(n1,n2,word1,word2,dp);
        int ans = n1 + n2 - (2*lcs);
        return ans;
    }
};
