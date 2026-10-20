/**
 * Problem: Merge Close Characters (3853)
 * Link: https://leetcode.com/problems/merge-close-characters/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeCharacters(string s, int k) {
        bool foundMerge = true;
        while (foundMerge) {
            foundMerge = false;
            for (int i = 0; i < s.length(); ++i) {
                for (int j = i + 1; j <= i + k && j < s.length(); ++j) {
                    if (s[i] == s[j]) {
                        s.erase(j, 1);
                        foundMerge = true;
                        break; 
                    }
                }
                if (foundMerge) {
                    break;
                }
            }
        }
        
        return s;
    }
};
