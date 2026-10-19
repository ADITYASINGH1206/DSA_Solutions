/**
 * Problem: Sort Colors (75)
 * Link: https://leetcode.com/problems/sort-colors/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int ones = 0;
        int twos = 0;
        for(int i =0;i<nums.size();i++){
            if(nums[i] == 0){
                zero++;
            }
            else if(nums[i] ==1 ){
                ones++;
            }else{
                twos++;
            }
        }
        for(int i = 0;i<nums.size();i++){
            if(zero){
                nums[i] =0;
                zero--;
            }else if(ones){
                nums[i] = 1;
                ones--;
            }else{
                nums[i] = 2;

            }
        }
    }
};
