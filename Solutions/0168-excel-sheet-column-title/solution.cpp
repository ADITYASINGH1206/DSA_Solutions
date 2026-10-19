/**
 * Problem: Excel Sheet Column Title (168)
 * Link: https://leetcode.com/problems/excel-sheet-column-title/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber>0){
            columnNumber--;
            int ch = 'A'+columnNumber%26;
            ans+=ch;
            columnNumber/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};
