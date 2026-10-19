/**
 * Problem: Remove Element (27)
 * Link: https://leetcode.com/problems/remove-element/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int y = 0;
        for (int x : nums) {
            if (x != val) {
                nums[y++] = x;
            }
        }
        return y;
    }
};
