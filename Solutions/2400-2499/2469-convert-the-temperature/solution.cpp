/**
 * Problem: Convert the Temperature (2469)
 * Link: https://leetcode.com/problems/convert-the-temperature/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double>ans(2);
        ans[0] = celsius+273.15;
        ans[1] = (celsius*1.8) +32.0;
        return ans;
    }
};
