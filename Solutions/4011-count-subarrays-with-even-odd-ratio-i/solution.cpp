/**
 * Problem: Count Subarrays With Even Odd Ratio I (4011)
 * Link: https://leetcode.com/problems/count-subarrays-with-even-odd-ratio-i/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int ans =0;
        for(int i =0;i<n;i++){
            int odd = 0 ,even =0;
            for(int j =i;j<n;j++){
                if(nums[j]%2==0){
                    even++;
                }else{
                    odd++;
                }
                if(odd && even*b<=odd*a){
                    ans++;
                }
            }
        }
        return ans;
    }
};
