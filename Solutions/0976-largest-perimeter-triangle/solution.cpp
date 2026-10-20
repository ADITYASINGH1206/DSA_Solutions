/**
 * Problem: Largest Perimeter Triangle (976)
 * Link: https://leetcode.com/problems/largest-perimeter-triangle/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.rbegin(),nums.rend());
        for(int i =0;i<n-2;i++){
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];
            if(a<(b+c)) return a+b+c;
        }
        return 0;
    }
};
