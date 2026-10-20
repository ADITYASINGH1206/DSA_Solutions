/**
 * Problem: Maximum Value of Concatenated Binary Segments (3897)
 * Link: https://leetcode.com/problems/maximum-value-of-concatenated-binary-segments/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        vector<string> segments;
        for(int i = 0; i < n; i++) {
            string temp = string(nums1[i], '1') + string(nums0[i], '0');
            segments.push_back(temp);
        }
        
        sort(segments.begin(), segments.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        
        long long MOD = 1e9 + 7;
        long long ans = 0;
        
        for (string seg : segments) {
            for (char c : seg) {
                ans = (ans * 2 + (c - '0')) % MOD;
            }
        }
        
        return ans;
    }
};
