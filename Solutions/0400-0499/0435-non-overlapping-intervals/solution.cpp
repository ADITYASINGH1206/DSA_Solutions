/**
 * Problem: Non-overlapping Intervals (435)
 * Link: https://leetcode.com/problems/non-overlapping-intervals/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int ans = 0;
        int last_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < last_end) {
                ans++; 
            } else {
                last_end = intervals[i][1];
            }
        }
        return ans;
    }
};
