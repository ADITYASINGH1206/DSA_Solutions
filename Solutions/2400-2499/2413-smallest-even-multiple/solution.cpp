/**
 * Problem: Smallest Even Multiple (2413)
 * Link: https://leetcode.com/problems/smallest-even-multiple/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestEvenMultiple(int n) {
        int ans =n;
        if(n%2 !=0){
            return ans = n*2;
        }
        return ans;
    }
};
