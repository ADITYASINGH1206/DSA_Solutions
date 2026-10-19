/**
 * Problem: To Lower Case (709)
 * Link: https://leetcode.com/problems/to-lower-case/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for(auto& x :s){
            x= tolower(x);
        }
        return s;
    }
};
