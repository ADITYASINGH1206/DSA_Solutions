/**
 * Problem: Maximize Sum of At Most K Distinct Elements (3684)
 * Link: https://leetcode.com/problems/maximize-sum-of-at-most-k-distinct-elements/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int> st(nums.begin(), nums.end()); 
        
        vector<int> ans;
        int count = 0;

        for(auto it = st.rbegin(); it != st.rend() && count < k; ++it){
            ans.push_back(*it);
            count++;
        }
        
        return ans;
    }
};
