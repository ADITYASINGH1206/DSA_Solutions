/**
 * Problem: Maximum Distance Between a Pair of Values (1855)
 * Link: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        reverse(nums2.begin(), nums2.end());
        for (int i = 0; i < nums1.size(); ++i) {
            int j = nums2.size() - (lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin()) - 1;
            ans = max(ans, j - i);
        }
        return ans;
    }
};
