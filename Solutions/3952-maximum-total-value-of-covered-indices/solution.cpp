/**
 * Problem: Maximum Total Value of Covered Indices (3952)
 * Link: https://leetcode.com/problems/maximum-total-value-of-covered-indices/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        long long ans = 0;
        int i = 0;
        
        while (i < n) {
            if (s[i] == '1') {
                int start = i;
                while (i < n && s[i] == '1') {
                    i++;
                }
                int end = i - 1;
                
                if (start > 0) {
                    long long sum = 0;
                    int mini = nums[start - 1]; 
                    for (int j = start - 1; j <= end; j++) {
                        sum += nums[j];
                        mini = min(mini, nums[j]);
                    }
                    ans += (sum - mini);
                } else {
                    for (int j = start; j <= end; j++) {
                        ans += nums[j];
                    }
                }
            } else {
                i++;
            }
        }
        
        return ans;
    }
};
