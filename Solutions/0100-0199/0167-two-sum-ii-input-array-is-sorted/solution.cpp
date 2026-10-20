/**
 * Problem: Two Sum II - Input Array Is Sorted (167)
 * Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans = {-1,-1};
        int n = numbers.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            if(numbers[low]+numbers[high] > target){
                high = high-1;
            }
            else if(numbers[low] + numbers[high] < target){
                low = low +1;
            }else{
                ans[0] = low+1;
                ans[1] = high+1;
                return ans;
            }
        }

        return ans;
    }
};
