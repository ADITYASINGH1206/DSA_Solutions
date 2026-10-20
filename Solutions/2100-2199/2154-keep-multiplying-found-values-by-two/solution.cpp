/**
 * Problem: Keep Multiplying Found Values by Two (2154)
 * Link: https://leetcode.com/problems/keep-multiplying-found-values-by-two/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        bool found = true;
        while(found){
            found = false;
            for(int i = 0;i<n;i++){
                if(nums[i] == original){
                    original *= 2;
                    found = true;
                    break;
                }
            }
        }

        return original;
    }
};
