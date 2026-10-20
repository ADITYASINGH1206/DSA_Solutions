/**
 * Problem: Minimum Operations to Make Array Modulo Alternating I (3937)
 * Link: https://leetcode.com/problems/minimum-operations-to-make-array-modulo-alternating-i/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = LLONG_MAX; 
        
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y) continue; 
                long long current_ops = 0;
                for (int i = 0; i < n; i++) {
                    int r = nums[i] % k;
                    if (i % 2 == 0) {
                        int dist = abs(r - x);
                        current_ops += min(dist, k - dist);
                    } else {
                        int dist = abs(r - y);
                        current_ops += min(dist, k - dist);
                    }
                }
                
                if (current_ops < ans) {
                    ans = current_ops;
                }
            }
        }
        
        return ans;
    }
};
