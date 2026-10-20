/**
 * Problem: Minimum Operations to Transform Array into Alternating Prime (3896)
 * Link: https://leetcode.com/problems/minimum-operations-to-transform-array-into-alternating-prime/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool primecheck(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        
    
        return true;
    }
    int prime(int n) {
        if (n <= 2) return 2;
        int curr = n;
        while (!primecheck(curr)) {
            curr++;
        }
        return curr;
    }

    int nprime(int n) {
        if (n <= 1) return n; 
        int curr = n;
        while (primecheck(curr)) {
            curr++;
        }
        return curr;
    }


    int minOperations(vector<int>& nums) {
        int ans = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                int target = prime(nums[i]);
                ans += (target - nums[i]);
            } else {
                int target = nprime(nums[i]);
                ans += (target - nums[i]);
            }
        }
        
        return ans;
    }
};
