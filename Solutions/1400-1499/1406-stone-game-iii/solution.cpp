/**
 * Problem: Stone Game III (1406)
 * Link: https://leetcode.com/problems/stone-game-iii/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static string stoneGameIII(vector<int>& stoneValue) {
        const int n=stoneValue.size();
        if (n==1) 
            return stoneValue[0]>0?"Alice":(stoneValue[0]<0?"Bob":"Tie");
        if (n==2){
            if(stoneValue[0]<0 )
                return stoneValue[0]+stoneValue[1]>0?"Alice":(stoneValue[0]!=stoneValue[1]?"Bob":"Tie");
            return "Alice";
        }
        int dp[3]={0};
        dp[n%3]=0;
        dp[(n-1)%3]=stoneValue[n-1]-dp[n%3];
        dp[(n-2)%3]=max(stoneValue[n-2]-dp[(n-1)%3], stoneValue[n-2]+stoneValue[n-1]-dp[n%3]);
        for (int i=n-3; i>=0; i--){
            const int s0=stoneValue[i], s1=stoneValue[i+1], s2=stoneValue[i+2];
            int res=s0-dp[(i+1)%3];
            res=max(res, s0+s1-dp[(i+2)%3]);
            res=max(res, s0+s1+s2-dp[(i+3)%3]);
            dp[i%3]=res;
        }
        int win=dp[0];
        return win>0?"Alice":(win<0?"Bob":"Tie");
        
    }
};
