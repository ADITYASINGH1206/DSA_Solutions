/**
 * Problem: Minimum Absolute Difference Between Two Values (3880)
 * Link: https://leetcode.com/problems/minimum-absolute-difference-between-two-values/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int one = -1;
        int two = -1;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                one = i;
                if (two != -1) {
                    ans = min(ans, i - two);
                }
            } else if (nums[i] == 2) {
                two = i;
                if (one != -1) {
                    ans = min(ans, i - one);
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};
