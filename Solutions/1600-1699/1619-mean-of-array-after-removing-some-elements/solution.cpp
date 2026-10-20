/**
 * Problem: Mean of Array After Removing Some Elements (1619)
 * Link: https://leetcode.com/problems/mean-of-array-after-removing-some-elements/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int length = arr.size();
        int fivePercent = length * 5 /100;
        int sum = accumulate(arr.begin()+fivePercent,arr.end()-fivePercent,0);
        int remainingSize = length - (2 * fivePercent);
        double mean = sum/(double)remainingSize;
        return mean;
    }
};
