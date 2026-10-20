/**
 * Problem: Maximum Number of Balloons (1189)
 * Link: https://leetcode.com/problems/maximum-number-of-balloons/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> count(26, 0);
        for (char ch : text) {
            count[ch - 'a']++;
        }
        return min({
            count['b' - 'a'], 
            count['a' - 'a'], 
            count['l' - 'a'] / 2, 
            count['o' - 'a'] / 2, 
            count['n' - 'a']
        });
    }
};
