/**
 * Problem: Find the Prefix Common Array of Two Arrays (2657)
 * Link: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        vector<int> count1(n + 1);
        vector<int> count2(n + 1);
        for (int i = 0; i < n; ++i) {
            count1[A[i]]++;
            count2[B[i]]++;
            for (int j = 1; j <= n; ++j) {
                ans[i] += min(count1[j], count2[j]);
            }
        }
        return ans;
    }
};
