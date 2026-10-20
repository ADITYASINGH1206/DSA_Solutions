/**
 * Problem: Count Shadow Pairs I (4054)
 * Link: https://leetcode.com/problems/count-shadow-pairs-i/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> next_smaller(n, n);
        vector<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.back()] > nums[i]) {
                next_smaller[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }
        
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int right_bound = next_smaller[i] - 1; 
            
            if (right_bound > i) {
                auto& indices = pos[nums[i]];
                int count_equal = upper_bound(indices.begin(), indices.end(), right_bound) - 
                                  upper_bound(indices.begin(), indices.end(), i);
                ans += (right_bound - i) - count_equal;
            }
        }
        
        return ans;
    }
};
