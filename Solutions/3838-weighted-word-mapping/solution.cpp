/**
 * Problem: Weighted Word Mapping (3838)
 * Link: https://leetcode.com/problems/weighted-word-mapping/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            int count = 0; 
            for(int j = 0; j < word.size(); j++) {
                count += weights[word[j] - 'a'];
            }
            int r = count % 26;
            char chrs = 'z' - r;
            
            ans += chrs;
        }
        
        return ans;
    }
};
