/**
 * Problem: Minimum K to Reduce Array Within Limit (3824)
 * Link: https://leetcode.com/problems/minimum-k-to-reduce-array-within-limit/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumK(vector<int>& nums) {
        vector<int> v = nums;
        long long low=1;
        long long high = 1000000000;
        long long ans = high;
        while(low<=high){
            long long k = low + (high-low )/2;
            long long total = 0;
            for(int p:v){
                total += (p+k-1)/k;
            }
            if(total <= k*k){
                ans = k;
                high = k-1;
            }else{
                low = k+1;
            }
        }
        return (int)ans;
        
    }
};
