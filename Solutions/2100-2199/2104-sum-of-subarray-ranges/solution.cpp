/**
 * Problem: Sum of Subarray Ranges (2104)
 * Link: https://leetcode.com/problems/sum-of-subarray-ranges/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        vector<int> left_min(n);
        vector<int> right_min(n);
        vector<int> left_max(n);
        vector<int> right_max(n);

        stack<int> s1;
        stack<int> s2;
        stack<int> s3;
        stack<int> s4;

        
        for (int i = 0; i < n; i++) {
            while (!s1.empty() && nums[s1.top()] >= nums[i]) {
                s1.pop();
            }
            left_min[i] = s1.empty() ? i + 1 : i - s1.top();
            s1.push(i);
        }
        
        for (int i = n - 1; i >= 0; i--) {
            while (!s2.empty() && nums[s2.top()] > nums[i]) {
                s2.pop();
            }
            right_min[i] = s2.empty() ? n - i : s2.top() - i;
            s2.push(i);
        }


        for (int i = 0; i < n; i++) {
            while (!s3.empty() && nums[s3.top()] <= nums[i]) {
                s3.pop();
            }
            left_max[i] = s3.empty() ? i + 1 : i - s3.top();
            s3.push(i);
        }
        
        for (int i = n - 1; i >= 0; i--) {
            while (!s4.empty() && nums[s4.top()] < nums[i]) {
                s4.pop();
            }
            right_max[i] = s4.empty() ? n - i : s4.top() - i;
            s4.push(i);
        }

        for(int i = 0;i<n;i++){
            long long min_sum = (long long)nums[i]*left_min[i]*right_min[i];
            long long max_sum = (long long)nums[i]*left_max[i]*right_max[i];

            ans += max_sum-min_sum;
        }
        return ans;
    }
};
