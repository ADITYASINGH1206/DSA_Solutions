/**
 * Problem: Find Smallest Letter Greater Than Target (744)
 * Link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
        return letters[i % letters.size()];
    }
};
