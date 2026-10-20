/**
 * Problem: Make Array Zero by Subtracting Equal Amounts (2357)
 * Link: https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return s.size() - s.count(0);
    }
};
