/**
 * Problem: Check ASCII Palindromic (4030)
 * Link: https://leetcode.com/problems/check-ascii-palindromic/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindromic(string s) {
        string binary = "";
        for (char c : s) {
            int ascii = int(c);
            string bin = bitset<8>(ascii).to_string();
            binary += bin;
        }
        int i = 0;
        int j = binary.size() - 1;

        while (i < j) {
            if (binary[i] != binary[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
