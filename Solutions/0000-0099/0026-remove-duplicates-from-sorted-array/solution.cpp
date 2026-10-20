/**
 * Problem: Remove Duplicates from Sorted Array (26)
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j =1;j<nums.size();j++){
            if(nums[j]!= nums[i]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};
