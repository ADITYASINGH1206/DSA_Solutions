/**
 * Problem: Edit Distance (72)
 * Link: https://leetcode.com/problems/edit-distance/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int i,int j,string& w1,string& w2,vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(w1[i] == w2[j]) return dp[i][j] = f(i-1,j-1,w1,w2,dp);
        return dp[i][j] = 1 + min(f(i-1,j,w1,w2,dp),min(f(i,j-1,w1,w2,dp),f(i-1,j-1,w1,w2,dp)));
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return f(n1-1,n2-1,word1,word2,dp);
        
    }
};
