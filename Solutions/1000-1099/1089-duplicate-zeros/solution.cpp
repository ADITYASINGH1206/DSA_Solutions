/**
 * Problem: Duplicate Zeros (1089)
 * Link: https://leetcode.com/problems/duplicate-zeros/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                arr.insert(arr.begin() + (i + 1), 0);
                i = i + 1;
                arr.pop_back();
            }
        }
    }
};
