/**
 * Problem: Find the Encrypted String (3210)
 * Link: https://leetcode.com/problems/find-the-encrypted-string/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ans = "";
        int n = s.size();
        for(int i = 0;i < n;i++){
            int place = (k + i) %n;
            char temp = s[place];
            ans += temp;
        }
        return ans;
    }
};
