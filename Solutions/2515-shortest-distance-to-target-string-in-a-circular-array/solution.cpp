/**
 * Problem: Shortest Distance to Target String in a Circular Array (2515)
 * Link: https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = n;
        for (int i = 0; i < n; ++i) {
            auto w = words[i];
            if (w == target) {
                int t = abs(i - startIndex);
                ans = min(ans, min(t, n - t));
            }
        }
        return ans == n ? -1 : ans;
    }
};
