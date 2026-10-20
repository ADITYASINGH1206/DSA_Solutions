/**
 * Problem: Count Monobit Integers (3827)
 * Link: https://leetcode.com/problems/count-monobit-integers/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMonobit(int n) {
        int ans = 1;
        int num = 1;
        while (num <= n){
            ans++;
            num = (num<<1) | 1;
        }
        return ans;
    }
};
