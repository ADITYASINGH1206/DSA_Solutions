/**
 * Problem: Find the Length of the Longest Common Prefix (3043)
 * Link: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s;
        for (int x : arr1) {
            for (; x; x /= 10) {
                s.insert(x);
            }
        }
        int ans = 0;
        for (int x : arr2) {
            for (; x; x /= 10) {
                if (s.count(x)) {
                    ans = max(ans, (int) log10(x) + 1);
                    break;
                }
            }
        }
        return ans;
    }
};
