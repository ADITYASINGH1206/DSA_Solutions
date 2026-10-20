/**
 * Problem: Check if the Sentence Is Pangram (1832)
 * Link: https://leetcode.com/problems/check-if-the-sentence-is-pangram/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> ch(26,0);
        int ans = true;
        for(char c:sentence){
            ch[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(!ch[i]){
                ans = false;
                break;
            }
        }
        return ans;
    }
};
