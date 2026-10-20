/**
 * Problem: Maximum Odd Binary Number (2864)
 * Link: https://leetcode.com/problems/maximum-odd-binary-number/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        if(n == 1) return s;

        int r = n - 1;
        int l = n - 2;
        while(s[r] != '1'){
            if(s[l] == '1') swap(s[l], s[r]);
            else{
                l--;
            }
        }
        l = 0;
        r = 0; 
        while(r < n - 1 && l < n - 1) {
            if(s[l] == '1') {
                l++;
                r = max(r, l); 
            }
            else {
                while(r < n - 1 && s[r] != '1') {
                    r++;
                }
                if (r < n - 1) {
                    swap(s[l], s[r]);
                    l++;
                    r++;
                }
            }
        }
        
        return s;
    }
};
