/**
 * Problem: Minimum Index of a Valid Split (2780)
 * Link: https://leetcode.com/problems/minimum-index-of-a-valid-split/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int majorityEle = 0;
        int maxFreq = 0;
        for (int num : nums) {
            freq[num]++;
            if (freq[num] > maxFreq) {
                maxFreq = freq[num];
                majorityEle = num;
            }
        }
        int leftCount = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == majorityEle) {
                leftCount++;
            }
            int rightCount = maxFreq - leftCount;
            int leftSize = i + 1;
            int rightSize = n - leftSize;
            if (leftCount * 2 > leftSize && rightCount * 2 > rightSize) {
                return i;
            }
        }

        return -1;
    }
};
