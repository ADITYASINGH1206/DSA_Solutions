/**
 * Problem: Rearrange Characters to Make Target String (2287)
 * Link: https://leetcode.com/problems/rearrange-characters-to-make-target-string/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int freq[26] = {0};
        int freq1[26] = {0};
        int ans = INT_MAX;
    
        for(char ch : s) {
            freq[ch - 'a']++;
        }
    
        for(char ch : target) {
            freq1[ch - 'a']++;
        }
        
        for(int i = 0; i < 26; i++) {
            if(freq1[i] > 0) {
                ans = min(ans, freq[i] / freq1[i]);
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};
