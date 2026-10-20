/**
 * Problem: Minimum Swaps to Move Zeros to End (3936)
 * Link: https://leetcode.com/problems/minimum-swaps-to-move-zeros-to-end/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int zero = 0;
        int n = nums.size();
        
        for (int num : nums) {
            if (num == 0) {
                zero++;
            }
        }
        
        if (zero == 0 || zero == n) return 0;
        
        int ans = 0;
        for (int i = n - zero; i < n; i++) {
            if (nums[i] != 0) {
                ans++;
            }
        }
        
        return ans;
    }
};
