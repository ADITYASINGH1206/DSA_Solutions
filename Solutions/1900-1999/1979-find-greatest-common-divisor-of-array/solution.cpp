/**
 * Problem: Find Greatest Common Divisor of Array (1979)
 * Link: https://leetcode.com/problems/find-greatest-common-divisor-of-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = INT_MAX;
        int largest = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] >largest){
                largest = nums[i];
            }
            if(nums[i]<smallest){
                smallest = nums[i];
            }
        }
        return __gcd(largest, smallest);
    }
};
