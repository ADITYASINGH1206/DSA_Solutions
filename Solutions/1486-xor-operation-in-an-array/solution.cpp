/**
 * Problem: XOR Operation in an Array (1486)
 * Link: https://leetcode.com/problems/xor-operation-in-an-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> arr(n,start);
        int ans = 0;
        for(int i = 0;i<n;i++){
            arr[i] = start + 2*i;
            ans ^= arr[i];
        }
        return ans;
        
    }
};
