/**
 * Problem: Find the Substring With Maximum Cost (2606)
 * Link: https://leetcode.com/problems/find-the-substring-with-maximum-cost/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int>val(26,0);
        for(int i =0;i<26;i++){
            val[i]=i+1;
        }
        for(int i =0;i<chars.size();i++){
            char ch= chars[i];
            val[ch-'a']=vals[i];
        }
        int cost = val[s[0]-'a'];
        int ans = max(cost,0);
        for(int i =1;i<s.size();i++){
            int ch = s[i]-'a';
            cost=max(val[ch],val[ch]+cost);
            ans=max(ans,cost);
        }
        return ans;
    }
};
