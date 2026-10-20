/**
 * Problem: Trionic Array I (3637)
 * Link: https://leetcode.com/problems/trionic-array-i/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool ans = true;
        int dirchange = 0;
        int total =0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]>0){
                if(dirchange == 0){
                    dirchange = 1;
                    total++;
                }
                else if(dirchange == -1){
                    dirchange =1;
                    total++;
                }
            }
            if(nums[i]-nums[i-1]<0){
                if(dirchange == 0){
                    return false;
                }
                else if(dirchange == 1){
                    dirchange = -1;
                    total++;
                }
            }
            if(nums[i]==nums[i-1]){
                return false;
            }
        }
        if(total != 3){
            ans = false;
        }
        return ans;
        
    }
};
