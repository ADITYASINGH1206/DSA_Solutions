/**
 * Problem: Divide Array Into Equal Pairs (2206)
 * Link: https://leetcode.com/problems/divide-array-into-equal-pairs/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int frequencies[501] = {0};
        
        for (int num : nums) {
            frequencies[num]++;
        }
        
        for (int i = 1; i <= 500; i++) {
            if (frequencies[i] % 2 != 0) {
                return false;
            }
        }
        
        return true;
    }
};
