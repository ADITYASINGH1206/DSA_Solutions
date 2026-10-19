/**
 * Problem: Majority Element (169)
 * Link: https://leetcode.com/problems/majority-element/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =0;
        int ans=0;
        for(int x: nums){
           if(count == 0){
                ans = x;
                count =1;
            }
            else{
                if(x == ans){
                    count++;
                }
                else{
                    count--;
                }
            }
        }
        return ans;
    }
};
