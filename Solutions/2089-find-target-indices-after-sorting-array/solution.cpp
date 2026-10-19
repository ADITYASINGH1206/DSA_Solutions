/**
 * @file find-target-indices-after-sorting-array.cpp
 * @brief Solution for LeetCode problem 2089: Find Target Indices After Sorting Array.
 * @problem_link https://leetcode.com/problems/find-target-indices-after-sorting-array/
 * @difficulty Easy
 * @time_complexity O(N log N)
 * @space_complexity O(N)
 *
 * @details The problem asks us to find all indices where a target element appears
 *          in an array after it has been sorted in non-decreasing order. The solution
 *          involves two main steps: first, sorting the input array to group all
 *          occurrences of the target together, and then performing a linear scan
 *          to collect the indices of these target elements.
 */

#include <bits/stdc++.h> // Includes common C++ headers like vector, algorithm

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans; // Initialize an empty vector to store target indices
        
        // Sort the input array in non-decreasing order
        // This operation has a time complexity of O(N log N), where N is nums.size()
        // After sorting, all occurrences of 'target' will be contiguous.
        sort(nums.begin(), nums.end());
        
        int n = nums.size(); // Get the size of the array for efficient iteration
        
        // Iterate through the sorted array from beginning to end
        // This linear scan has a time complexity of O(N).
        for(int i = 0; i < n; i++){
            // If the current element matches the target value
            if(nums[i] == target) {
                // Add its 0-indexed position to our result vector
                ans.push_back(i);
            }
        }
        
        return ans; // Return the vector containing all found target indices
    }
};
