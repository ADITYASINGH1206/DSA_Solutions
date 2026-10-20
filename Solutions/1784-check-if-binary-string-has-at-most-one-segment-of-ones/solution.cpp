/**
 * Problem: Check if Binary String Has at Most One Segment of Ones (1784)
 * Link: https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == -1;
    }
};
