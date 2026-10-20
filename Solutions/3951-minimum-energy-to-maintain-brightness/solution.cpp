/**
 * Problem: Minimum Energy to Maintain Brightness (3951)
 * Link: https://leetcode.com/problems/minimum-energy-to-maintain-brightness/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long ans = 0;
        if (intervals.empty() || brightness <= 0) {
            return 0;
        }
        
        long long energy = (brightness + 2) / 3;
        
        sort(intervals.begin(), intervals.end());
        
        long long totalTime = 0;
        long long start = intervals[0][0];
        long long end = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= end) {
                end = max(end, (long long)intervals[i][1]);
            } else {
                totalTime += (end - start + 1);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        totalTime += (end - start + 1);
        ans = totalTime * energy;
        
        return ans;
    }
};
