/**
 * Problem: Partition Array According to Given Pivot (2161)
 * Link: https://leetcode.com/problems/partition-array-according-to-given-pivot/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans;
        for (int x : nums) {
            if (x < pivot) {
                ans.push_back(x);
            }
        }
        for (int x : nums) {
            if (x == pivot) {
                ans.push_back(x);
            }
        }
        for (int x : nums) {
            if (x > pivot) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
