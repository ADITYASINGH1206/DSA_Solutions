/**
 * Problem: Check if Two Chessboard Squares Have the Same Color (3274)
 * Link: https://leetcode.com/problems/check-if-two-chessboard-squares-have-the-same-color/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int c1 = (coordinate1[0]-'a')+(coordinate1[1]-'1');
        int c2 = (coordinate2[0]-'a')+(coordinate2[1]-'1');
        return c1%2==c2%2 ? true:false;
    }
};
