/**
 * Problem: Maximum Element After Decreasing and Rearranging (1846)
 * Link: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (int i = 1; i < arr.size(); i++) {
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }
        return arr.back();
    }
};
