/**
 * Problem: Reverse Degree of a String (3498)
 * Link: https://leetcode.com/problems/reverse-degree-of-a-string/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int ans =0;
        for(int i =0;i<s.size();i++){
            int degree = (26-(s[i]-'a'))*(i+1);
            ans += degree;
        }
        return ans;
    }
};
