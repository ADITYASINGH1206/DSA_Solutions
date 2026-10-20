/**
 * Problem: Construct Uniform Parity Array II (3876)
 * Link: https://leetcode.com/problems/construct-uniform-parity-array-ii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;

        for (int x : nums1) {
            if (x % 2 == 0) {
                minEven = min(minEven, x);
            } else {
                minOdd = min(minOdd, x);
            }
        }

        if (minOdd == INT_MAX) {
            return true;
        }

        return minOdd < minEven;
    }
};
