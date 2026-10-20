/**
 * Problem: Count Asterisks (2315)
 * Link: https://leetcode.com/problems/count-asterisks/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countAsterisks(string s) {
        int counter = 0;
        int ans =0;
        for(auto & c: s){
            if(c== '|') counter++;
            if(c == '*' && counter%2==0) ans++;
        }
        return ans;
    }
};
