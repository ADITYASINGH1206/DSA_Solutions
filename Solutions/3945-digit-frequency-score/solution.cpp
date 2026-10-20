/**
 * Problem: Digit Frequency Score (3945)
 * Link: https://leetcode.com/problems/digit-frequency-score/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitFrequencyScore(int n) {
        int ans = 0;
        int temp = n;
        while(temp){
            int digit = temp%10;
            ans += digit;
            temp/=10;
        }
        return ans;
    }

};
