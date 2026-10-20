/**
 * Problem: Last Moment Before All Ants Fall Out of a Plank (1503)
 * Link: https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxLeft = left.empty() ? 0 : *max_element(left.begin(), left.end());
        int minRight = right.empty() ? n : *min_element(right.begin(), right.end());
    
        return max(maxLeft, n - minRight);
    }
};
