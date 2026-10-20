/**
 * Problem: Maximum Count of Positive Integer and Negative Integer (2529)
 * Link: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCount(std::vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int l = 0, r = n - 1;
        int negCount = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < 0) {
                negCount = mid + 1; 
                l = mid + 1;        
            } else {
                r = mid - 1;        
            }
        }
        
        l = 0, r = n - 1;
        int posStart = n; 
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > 0) {
                posStart = mid;     
                r = mid - 1;        
            } else {
                l = mid + 1;        
            }
        }
        
        int posCount = n - posStart;
        ans = max(negCount, posCount);
        return ans;
    }
};
