/**
 * Problem: First Matching Character From Both Ends (3884)
 * Link: https://leetcode.com/problems/first-matching-character-from-both-ends/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMatchingIndex(string s) {
        int n = s.size();

        for(int i =0;i<n;i++){
            if(s[i] == s[n-i-1]){
                return i;
            }
        }
        return -1;
    }
};
