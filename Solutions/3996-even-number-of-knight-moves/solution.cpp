/**
 * Problem: Even Number of Knight Moves (3996)
 * Link: https://leetcode.com/problems/even-number-of-knight-moves/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        return (start[0] + start[1] + target[0] + target[1]) % 2 == 0;
    }
};
