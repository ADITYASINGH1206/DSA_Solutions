/**
 * Problem: Minimum Average of Smallest and Largest Elements (3194)
 * Link: https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        double ans = INT_MAX;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i = 0;
        while(i<n/2){
            double maxi = nums[n-i-1];
            double mini = nums[i];
            double average = (maxi+mini)/2;
            ans = min(ans,average);
            i++;
        }


        return ans;
    }
};
