/**
 * Problem: Find the Highest Altitude (1732)
 * Link: https://leetcode.com/problems/find-the-highest-altitude/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int x =0, ans =0;
        for (int i=0;i<gain.size();i++){
            x+=gain[i];
            ans =max(ans,x);
        }
        return ans;
    }
};
