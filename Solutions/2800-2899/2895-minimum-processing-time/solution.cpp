/**
 * Problem: Minimum Processing Time (2895)
 * Link: https://leetcode.com/problems/minimum-processing-time/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(),processorTime.end());
        sort(tasks.rbegin(),tasks.rend());
        int n = processorTime.size();
        int ans = INT_MIN;
        for(int i = 0;i<n;i++){
            ans = max(ans,processorTime[i]+tasks[4*i]);
        }

        return ans;
    }
};
