/**
 * Problem: Merge Two 2D Arrays by Summing Values (2570)
 * Link: https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int left = 0;
        int right = 0;
        while(left < n1 && right < n2){
            if(nums1[left][0] < nums2[right][0]){
                ans.push_back({nums1[left][0],nums1[left][1]});
                left++;
            }
            else if(nums1[left][0] > nums2[right][0]){
                ans.push_back({nums2[right][0],nums2[right][1]});
                right++;
            }else{
                ans.push_back({nums1[left][0],nums1[left][1]+nums2[right][1]});
                left++;
                right++;
            }
        }
        while(left < n1){
            ans.push_back({nums1[left][0],nums1[left][1]});
            left++;
        }
        while(right < n2){
            ans.push_back({nums2[right][0],nums2[right][1]});
            right++;
        }
        return ans;
    }
};
