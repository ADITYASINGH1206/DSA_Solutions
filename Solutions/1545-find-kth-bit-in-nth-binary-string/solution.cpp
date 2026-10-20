/**
 * Problem: Find Kth Bit in Nth Binary String (1545)
 * Link: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        
        int mid = 1 << (n - 1);
        
        if (k == mid) {
            return '1'; 
        } else if (k < mid) {
            return findKthBit(n - 1, k);
        } else {
            int mirrored_k = (1 << n) - k;
            char bit = findKthBit(n - 1, mirrored_k);
            return bit == '0' ? '1' : '0'; 
        }
    }
};
