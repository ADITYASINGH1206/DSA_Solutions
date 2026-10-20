/**
 * Problem: Can Make Arithmetic Progression From Sequence (1502)
 * Link: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int dif = arr[1]-arr[0];
        int n = arr.size();
        for(int i = 2;i<n;i++){
            if(dif != arr[i]-arr[i-1]) return false;
        }
        return true;
    }
};
