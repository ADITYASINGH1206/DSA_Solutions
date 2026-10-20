/**
 * Problem: Valid Subarrays With Matching Sum Digits I (3969)
 * Link: https://leetcode.com/problems/valid-subarrays-with-matching-sum-digits-i/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(long long sum,int x){
        int last = sum%10;
        long long first = sum;
        while(first>9){
            first /=10;
        }

        return ((first==x) && (last == x));
    }
    int countValidSubarrays(vector<int>& nums, int x) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            long long sum = 0;
            for(int j =i;j<n;j++){
                sum += nums[j];
                if(check(sum,x)) ans++;
            }
        }
        return ans;
    }
};
