/**
 * Problem: Sum of Compatible Numbers in Range I (3954)
 * Link: https://leetcode.com/problems/sum-of-compatible-numbers-in-range-i/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int ans=0;
        for(int i=max(1,n-k);i<=n+k;i++){
            if((n&i)==0)ans+=i;
        }
        return ans;
    }
};
