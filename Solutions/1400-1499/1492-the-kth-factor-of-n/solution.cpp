/**
 * Problem: The kth Factor of n (1492)
 * Link: https://leetcode.com/problems/the-kth-factor-of-n/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        for(int i=1;i<=n;i++){
            if(n%i==0) factors.push_back(i);
        }
        if(k<=factors.size()) return factors[k-1];

        return -1;
        
        
    }
};
