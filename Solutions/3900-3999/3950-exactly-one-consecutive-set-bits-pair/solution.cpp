/**
 * Problem: Exactly One Consecutive Set Bits Pair (3950)
 * Link: https://leetcode.com/problems/exactly-one-consecutive-set-bits-pair/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool consecutiveSetBits(int n) {
        int count = 0;
        int prev = 0;
        
        while (n > 0) {
            int cur = n % 2;
            
            if (cur == 1 && prev == 1) {
                count++;
            }
            
            prev = cur;
            n = n / 2;
        }
        
        return count == 1;
    }
};
