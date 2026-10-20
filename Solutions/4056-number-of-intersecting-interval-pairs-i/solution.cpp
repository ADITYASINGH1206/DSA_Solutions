/**
 * Problem: Number of Intersecting Interval Pairs I (4056)
 * Link: https://leetcode.com/problems/number-of-intersecting-interval-pairs-i/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        for(int i = 0; i < intervals.size(); i++){
            for(int j = i + 1; j < intervals.size(); j++){
                int c1 = intervals[i][0];
                int c2 = intervals[i][1];
                int c3 = intervals[j][0];
                int c4 = intervals[j][1];
                if(c1 <= c4 && c3 <= c2)cnt++;
            }
        }
        return cnt;
    }
};
