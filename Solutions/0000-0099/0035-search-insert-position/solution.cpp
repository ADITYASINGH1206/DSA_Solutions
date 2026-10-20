/**
 * Problem: Search Insert Position (35)
 * Link: https://leetcode.com/problems/search-insert-position/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) r= mid-1;
            else l = mid+1;
        }

        return l;
    }
};
