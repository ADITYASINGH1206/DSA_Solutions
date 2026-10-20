/**
 * Problem: Decode the Slanted Ciphertext (2075)
 * Link: https://leetcode.com/problems/decode-the-slanted-ciphertext/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string ans;
        int cols = encodedText.size() / rows;
        for (int j = 0; j < cols; ++j) {
            for (int x = 0, y = j; x < rows && y < cols; ++x, ++y) {
                ans += encodedText[x * cols + y];
            }
        }
        while (ans.size() && ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};
