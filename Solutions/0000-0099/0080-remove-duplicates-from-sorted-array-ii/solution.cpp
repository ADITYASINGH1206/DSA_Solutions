/**
 * Problem: Remove Duplicates from Sorted Array II (80)
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
            if (i < 2 || n != nums[i-2])
                nums[i++] = n;
        return i;
    }
};
