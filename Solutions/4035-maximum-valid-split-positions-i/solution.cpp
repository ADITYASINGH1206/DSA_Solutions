/**
 * Problem: Maximum Valid Split Positions I (4035)
 * Link: https://leetcode.com/problems/maximum-valid-split-positions-i/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int skip = -1; skip < n; skip++) {

            vector<int> arr;
            arr.reserve(n);
            for (int i = 0; i < n; ++i) {
                if (i != skip) {
                    arr.push_back(nums[i]);
                }
            }
            int m = arr.size();
            if (m <= 1) continue; 

            vector<int> left(m), right(m);
            
            left[0] = arr[0];
            for (int i = 1; i < m; ++i) {
                left[i] = gcd(left[i - 1], arr[i]);
            }
            
            right[m - 1] = arr[m - 1];
            for (int i = m - 2; i >= 0; --i) {
                right[i] = gcd(right[i + 1], arr[i]);
            }
            int score = 0;
            for (int i = 0; i < m - 1; ++i) {
                if (left[i] == right[i + 1]) {
                    score++;
                }
            }
            ans = max(ans, score);
        }
        
        return ans;
    }
};
