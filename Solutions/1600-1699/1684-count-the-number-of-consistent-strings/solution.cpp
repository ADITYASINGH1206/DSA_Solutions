/**
 * Problem: Count the Number of Consistent Strings (1684)
 * Link: https://leetcode.com/problems/count-the-number-of-consistent-strings/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool isAllowed[26] = {false};
        for (char c : allowed) {
            isAllowed[c - 'a'] = true;
        }
        
        int count = words.size();
        
        for (const string& word : words) {
            for (char c : word) {
                if (!isAllowed[c - 'a']) {
                    count--; 
                    break;   
                }
            }
        }
        
        return count;
    }
};
