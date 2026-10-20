/**
 * Problem: Longest Balanced Subarray I (3719)
 * Link: https://leetcode.com/problems/longest-balanced-subarray-i/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int even = 0;
            int odd = 0;
            unordered_map<int,int> count;
            for(int j=i;j<n;j++){
                if(!count.contains(nums[j])){
                    if(nums[j] %2 == 0){
                        even++;
                    }else{
                        odd++;
                    }
                }
                if(even == odd && even != 0){
                    ans = max(ans,j-i+1);
                }
                count[nums[j]]++;

            }
        }
        return ans;
    }
};
