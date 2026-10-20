/**
 * Problem: Reduction Operations to Make the Array Elements Equal (1887)
 * Link: https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = n-1;i>0;i--){
            if(nums[i-1] != nums[i]){
                ans += n - i;
            }
        }

        return ans;
    }
};
