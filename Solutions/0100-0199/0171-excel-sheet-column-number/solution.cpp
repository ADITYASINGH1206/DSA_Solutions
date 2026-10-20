/**
 * Problem: Excel Sheet Column Number (171)
 * Link: https://leetcode.com/problems/excel-sheet-column-number/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0 ;
        for(int i = 0 ; i < columnTitle.size();i++){
            ans= ans*26+(columnTitle[i]-'A'+1);
        }
        return ans;
    }
};
