/**
 * Problem: Trim Trailing Vowels (3856)
 * Link: https://leetcode.com/problems/trim-trailing-vowels/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string trimTrailingVowels(string s) {
        while (!s.empty() && (s.back() == 'a' || s.back() == 'e' || 
                              s.back() == 'i' || s.back() == 'o' || 
                              s.back() == 'u')) {
            s.pop_back(); 
        }
        return s;
    }
};
