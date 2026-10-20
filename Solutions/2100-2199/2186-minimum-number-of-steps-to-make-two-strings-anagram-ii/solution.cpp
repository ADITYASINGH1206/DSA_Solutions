/**
 * Problem: Minimum Number of Steps to Make Two Strings Anagram II (2186)
 * Link: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        for(char ch:t){
            freq[ch-'a']--;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=abs(freq[i]);
        }
        return ans;
    }
};
