/**
 * Problem: Minimum Cost to Equalize Arrays Using Swaps (3868)
 * Link: https://leetcode.com/problems/minimum-cost-to-equalize-arrays-using-swaps/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> freq;
        unordered_map<int, int> count1;

        for (int i = 0; i < n; i++) {
            freq[nums1[i]]++;
            freq[nums2[i]]++;
            count1[nums1[i]]++;
        }

        for (auto it = freq.begin(); it != freq.end(); it++) {
            if (it->second % 2 != 0) {
                return -1;
            }
        }

        int swaps = 0;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            int val = it->first;
            int total = it->second;
            int target = total / 2;

            if (count1[val] > target) {
                swaps += (count1[val] - target);
            }
        }

        return swaps;
    }
};
