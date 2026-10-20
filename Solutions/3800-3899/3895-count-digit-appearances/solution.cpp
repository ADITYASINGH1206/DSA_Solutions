/**
 * Problem: Count Digit Appearances (3895)
 * Link: https://leetcode.com/problems/count-digit-appearances/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans = 0;
        for(int num : nums){
            int temp = num ;
            while(temp){
                int dig = temp%10;
                if(dig == digit) ans++;
                temp/=10;
                
            }
        }
        return ans;
    }
};
