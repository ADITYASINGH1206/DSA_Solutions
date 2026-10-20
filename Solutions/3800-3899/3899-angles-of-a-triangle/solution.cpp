/**
 * Problem: Angles of a Triangle (3899)
 * Link: https://leetcode.com/problems/angles-of-a-triangle/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<double> ans;
        double a = sides[0];
        double b = sides[1];
        double c = sides[2];
        
        if (a + b <= c || a + c <= b || b + c <= a) {
            return ans;
        }
        
        double aa = acos((b*b + c*c - a*a)/(2.0*b*c))*180.0/M_PI;
        double bb = acos((a*a + c*c - b*b)/(2.0*a*c))*180.0/M_PI;
        double cc = acos((a*a + b*b - c*c)/(2.0*a*b))*180.0/M_PI;
        
        ans.push_back(aa);
        ans.push_back(bb);
        ans.push_back(cc);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
