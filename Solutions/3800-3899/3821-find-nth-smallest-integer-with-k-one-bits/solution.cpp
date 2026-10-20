/**
 * Problem: Find Nth Smallest Integer With K One Bits (3821)
 * Link: https://leetcode.com/problems/find-nth-smallest-integer-with-k-one-bits/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long combinations[65][65];

    void initCombinations() {
        memset(combinations, 0, sizeof(combinations));
        for (int i = 0; i <= 64; i++) {
            combinations[i][0] = 1; // nC0 is always 1
            for (int j = 1; j <= i; j++) {
                combinations[i][j] = combinations[i - 1][j - 1] + combinations[i - 1][j];
            }
        }
    }

    long long nthSmallest(long long n, int k) {
        initCombinations();
        
        long long result = 0;
    
        for (int bit = 62; bit >= 0; bit--) {
            long long count = (bit >= k) ? combinations[bit][k] : 0;
            
            if (n > count) {
                result |= (1LL << bit);
                n -= count;
                k--;
                if (k == 0) break; 
            } else {

            }
        }
        
        return result;
    }
};
