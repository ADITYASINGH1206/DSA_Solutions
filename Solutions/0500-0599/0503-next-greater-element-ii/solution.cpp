/**
 * Problem: Next Greater Element II (503)
 * Link: https://leetcode.com/problems/next-greater-element-ii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack <int> stk;
        int n = nums.size();
        vector<int> ans(n);
        for(int i = n-1;i>-1;i--){
            while(!stk.empty() && stk.top() <= nums[i]){
                stk.pop();
            }
            stk.push(nums[i]);
        }
        for(int i = n-1;i>-1;i--){
            while(!stk.empty() && stk.top() <= nums[i]){
                stk.pop();
            }
            if(!stk.empty()){
                ans[i] = stk.top();
            }else{
                ans[i] = -1;
            }
            stk.push(nums[i]);
        }
        return ans;
    }
};
