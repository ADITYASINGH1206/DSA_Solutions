/**
 * Problem: Sum of Beauty of All Substrings (1781)
 * Link: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beauty(string s){
        vector<int> freq(26,0);
        for(char c :s){
            freq[c-'a']++;
        }
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i =0 ;i<26;i++){
            if(freq[i]>maxi){
                maxi = freq[i];
            }
            if(freq[i] != 0 && freq[i] <  mini){
                mini = freq[i];
            }
        }
        return maxi-mini;
    }
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int len = 1; len <= n - i; len++) {
                ans += beauty((s.substr(i, len)));
            }
        }
        return ans;
    }
};
