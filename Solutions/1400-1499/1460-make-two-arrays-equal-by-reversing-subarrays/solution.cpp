/**
 * Problem: Make Two Arrays Equal by Reversing Subarrays (1460)
 * Link: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> freq(1001,0);
        int n = target.size();
        for(int i = 0;i<n;i++){
            freq[target[i]]++;
        }

        for(int i =0;i<n;i++){
            if(freq[arr[i]] ==0) return false;
            freq[arr[i]]--;
        }

        return true;
    }
};
