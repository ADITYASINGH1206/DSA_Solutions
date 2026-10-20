/**
 * Problem: Merge Adjacent Equal Elements (3834)
 * Link: https://leetcode.com/problems/merge-adjacent-equal-elements/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<int> copy = nums;
        vector<long long> ans;
        for(int i: copy){
            ans.push_back((long long)i);
            while(ans.size() >=2 && ans.back() == ans[ans.size()-2]){
                long long newval = 2*ans.back();   
                ans.pop_back();
                ans.pop_back();
                ans.push_back(newval);
            }
        }

        return ans;
    }
};
