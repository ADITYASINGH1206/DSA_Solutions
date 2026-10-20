/**
 * Problem: Maximum Total Sum of K Selected Elements (3974)
 * Link: https://leetcode.com/problems/maximum-total-sum-of-k-selected-elements/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long ans = 0;
        sort(nums.begin(),nums.end());
        while(k >0){
            long long element = nums[nums.size()-1];
            k--;
            nums.pop_back();
            if(mul>0){
                ans += element*mul;
                mul--;
            }
            else{
                ans += element;
            }
        }
        return ans;
    }
};
