/**
 * Problem: Find Polygon With the Largest Perimeter (2971)
 * Link: https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int num:nums) ans+=num;
        sort(nums.rbegin(),nums.rend());
        for(int i = 0;i<n;i++){
            long long temp = ans - nums[i];
            if(nums[i] < temp ) return ans;
            else ans -= nums[i];
        }
        return -1;
    }
};
