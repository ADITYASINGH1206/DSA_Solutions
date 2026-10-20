/**
 * Problem: Number of Elapsed Seconds Between Two Times (3986)
 * Link: https://leetcode.com/problems/number-of-elapsed-seconds-between-two-times/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timeToSeconds(string& timeStr) {
        int h = stoi(timeStr.substr(0, 2));
        int m = stoi(timeStr.substr(3, 2));
        int s = stoi(timeStr.substr(6, 2));
        
        return (h * 3600) + (m * 60) + s;
    }
    int secondsBetweenTimes(string startTime,string endTime) {
        return timeToSeconds(endTime) - timeToSeconds(startTime);
    }
};
