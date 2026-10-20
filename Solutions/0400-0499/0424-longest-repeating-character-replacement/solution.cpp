/**
 * Problem: Longest Repeating Character Replacement (424)
 * Link: https://leetcode.com/problems/longest-repeating-character-replacement/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int n = s.size();
        int maxFreq = 0;
        unordered_map<char,int> mp;
        int l = 0;
        int r = 0;
        while(r<n){
            mp[s[r]]++;
            if(mp[s[r]] > maxFreq){
                maxFreq = mp[s[r]];
            }
            int len = r-l+1;
            if(len-maxFreq <= k){
                ans = max(ans,r-l+1);
            }else{
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};
