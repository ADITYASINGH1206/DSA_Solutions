/**
 * Problem: Maximum Nesting Depth of Two Valid Parentheses Strings (1111)
 * Link: https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int>maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int>ans (n,0);
        int depth = 0;

        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                depth++;
                ans[i] = depth % 2;
            } else {
                ans[i] = depth % 2;
                depth--;
            }
        }

        return ans;
    }
};
