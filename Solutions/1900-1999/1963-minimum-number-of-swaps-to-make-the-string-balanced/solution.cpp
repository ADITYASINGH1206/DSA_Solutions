/**
 * Problem: Minimum Number of Swaps to Make the String Balanced (1963)
 * Link: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int size = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '[')
                size++;
            else if (size > 0) 
                size--;
        }
        return (size + 1) / 2;
    }
};
