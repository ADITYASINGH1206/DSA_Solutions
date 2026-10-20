/**
 * Problem: Reverse String II (541)
 * Link: https://leetcode.com/problems/reverse-string-ii/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        for(int i = 0 ; i<n;i+=2*k){
            int left = i;
            int right=min(i+k-1,n-1);
            reverse(s.begin()+left,s.begin()+right+1);
        }  
        return s;
    }
};
