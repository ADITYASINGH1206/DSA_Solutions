/**
 * Problem: Sum of Subarray Minimums (907)
 * Link: https://leetcode.com/problems/sum-of-subarray-minimums/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        
        vector<int> left(n);
        vector<int> right(n);
        
        stack<int> s1; 
        stack<int> s2; 
        
        for (int i = 0; i < n; i++) {
            while (!s1.empty() && arr[s1.top()] >= arr[i]) {
                s1.pop();
            }
            left[i] = s1.empty() ? i + 1 : i - s1.top();
            s1.push(i);
        }
        
        for (int i = n - 1; i >= 0; i--) {
            while (!s2.empty() && arr[s2.top()] > arr[i]) {
                s2.pop();
            }
            right[i] = s2.empty() ? n - i : s2.top() - i;
            s2.push(i);
        }
        
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long contribution = (long long)arr[i] * left[i] * right[i];
            ans = (ans + contribution) % MOD;
        }
        
        return ans;
    }
};
