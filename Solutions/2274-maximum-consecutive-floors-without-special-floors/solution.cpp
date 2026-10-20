/**
 * Problem: Maximum Consecutive Floors Without Special Floors (2274)
 * Link: https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& A) {
        sort(begin(A), end(A));
        int n = A.size(), res = max(A[0] - bottom, top - A[n - 1]);
        for (int i = 1; i < n; ++i)
            res = max(res, A[i] - A[i - 1] - 1);
        return res;
    }
};
