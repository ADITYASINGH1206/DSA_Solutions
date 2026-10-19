/**
 * @file find-target-indices-after-sorting-array.cpp
 * @brief LeetCode Problem 2089: Find Target Indices After Sorting Array
 * @author [Your Name/Handle]
 * @date [Date]
 *
 * Problem Link: https://leetcode.com/problems/find-target-indices-after-sorting-array/
 * Difficulty: Easy
 *
 * Time Complexity: O(N log N)
 * Space Complexity: O(log N)
 */

#include <bits/stdc++.h> // Includes common headers like vector, algorithm

// Using the standard namespace to avoid prefixing std::
using namespace std;

class Solution {
public:
    // Function to find all indices of the target element after sorting the array
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans; // Initialize an empty vector to store target indices
        
        // Sort the input array in non-decreasing order.
        // This operation is crucial as it brings all occurrences of the target
        // value together, making them easy to find sequentially.
        sort(nums.begin(), nums.end());
        
        int n = nums.size(); // Get the size of the array for iteration
        
        // Iterate through the sorted array from the beginning to the end.
        for (int i = 0; i < n; ++i) {
            // If the current element at index 'i' matches the target value,
            // then 'i' is a target index. Add it to our result vector.
            if (nums[i] == target) {
                ans.push_back(i);
            }
        }
        
        return ans; // Return the list of all found target indices
    }
};
