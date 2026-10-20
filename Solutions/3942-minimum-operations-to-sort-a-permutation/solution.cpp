/**
 * Problem: Minimum Operations to Sort a Permutation (3942)
 * Link: https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
    
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                idx = i;
                break;
            }
        }
        
        bool asc = true;
        bool desc = true;
        
        for (int i = 1; i < n; i++) {
            if (nums[(idx + i) % n] != i) {
                asc = false;
            }
            if (nums[(idx + i) % n] != n - i) {
                desc = false;
            }
        }
        
        if (!asc && !desc) {
            return -1;
        }

        if (asc && desc) {
            return min({idx, n - idx + 2, n - idx, idx + 2});
        } else if (asc) {
            return min(idx, n - idx + 2);
        } else {
            return min(n - idx, idx + 2);
        }
    }
};
