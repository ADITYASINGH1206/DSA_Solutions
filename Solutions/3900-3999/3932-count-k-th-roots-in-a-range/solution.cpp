/**
 * Problem: Count K-th Roots in a Range (3932)
 * Link: https://leetcode.com/problems/count-k-th-roots-in-a-range/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int ans = 0;
        int l_min = ceil(pow(l,1.0/k) - 1e-9);
        int r_max = floor(pow(r,1.0/k) + 1e-9);
        ans = max(ans, r_max - l_min +1);

        return ans;
    }
};
