/**
 * Problem: Find Missing Elements (3731)
 * Link: https://leetcode.com/problems/find-missing-elements/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> freq(101,0);
        vector<int> ans;
        for(auto num : nums){
            freq[num]++;
        }
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        for(int i = mini;i<=maxi;i++){
            if(!freq[i]) ans.push_back(i);
        }
        return ans;
    }
};
