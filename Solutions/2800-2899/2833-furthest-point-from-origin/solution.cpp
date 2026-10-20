/**
 * Problem: Furthest Point From Origin (2833)
 * Link: https://leetcode.com/problems/furthest-point-from-origin/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(std::string moves) {
        int ans = 0;
        int l_count = 0, r_count = 0, u_count = 0;
        
        for (char c : moves) {
            if (c == 'L') l_count++;
            else if (c == 'R') r_count++;
            else u_count++;
        }
        
        ans = abs(l_count - r_count) + u_count;
        return ans;
    }
};
