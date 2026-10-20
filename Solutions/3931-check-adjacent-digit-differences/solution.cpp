/**
 * Problem: Check Adjacent Digit Differences (3931)
 * Link: https://leetcode.com/problems/check-adjacent-digit-differences/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.size();
        for(int i = 0;i<n-1;i++){
            int dif = abs((s[i]-'0') - (s[i+1]-'0'));
            if(dif > 2) return false;
        }
        return true;
        
    }
};
