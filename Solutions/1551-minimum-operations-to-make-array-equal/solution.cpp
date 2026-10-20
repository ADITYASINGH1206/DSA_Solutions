/**
 * Problem: Minimum Operations to Make Array Equal (1551)
 * Link: https://leetcode.com/problems/minimum-operations-to-make-array-equal/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        for(int i =0;i<n/2;i++){
            int temp = abs(((2*i)+1)-n);
            ans += temp;
        }
        return ans;
    }
};
