/**
 * Problem: Two Furthest Houses With Different Colors (2078)
 * Link: https://leetcode.com/problems/two-furthest-houses-with-different-colors/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0, n = colors.size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (colors[i] != colors[j])
                    ans = max(ans, abs(i - j));
        return ans;
    }
};
