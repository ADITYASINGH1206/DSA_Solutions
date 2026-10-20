/**
 * Problem: Relative Sort Array (1122)
 * Link: https://leetcode.com/problems/relative-sort-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxi = *max_element(arr1.begin(), arr1.end());
        vector<int> count(maxi + 1);

        for (int num : arr1) {
            count[num]++;
        }

        vector<int> ans;
        for (int num : arr2) {
            while (count[num] > 0) {
                ans.push_back(num);
                count[num]--;
            }
        }
        for (int num = 0; num <= maxi; num++) {
            while (count[num] > 0) {
                ans.push_back(num);
                count[num]--;
            }
        }
        return ans;
    }
};
