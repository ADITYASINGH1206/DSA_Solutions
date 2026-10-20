/**
 * Problem: Check if Array Is Sorted and Rotated (1752)
 * Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            cnt += nums[i] > (nums[(i + 1) % n]);
        }
        return cnt <= 1;
    }
};
