/**
 * Problem: Sum of Elements With Frequency Divisible by K (3712)
 * Link: https://leetcode.com/problems/sum-of-elements-with-frequency-divisible-by-k/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int ans = 0;
        vector<int> freq(101,0);
        for(int num:nums){
            freq[num]++;
        }
        for(int i = 1 ;i<101;i++){
            if(freq[i] != 0 && freq[i]%k ==0) ans+= i*freq[i];
        }
        return ans;

    }
};
