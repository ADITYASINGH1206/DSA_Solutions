/**
 * Problem: K Items With the Maximum Sum (2600)
 * Link: https://leetcode.com/problems/k-items-with-the-maximum-sum/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if(k>numOnes){
            k-=numOnes;
            if(k>numZeros){
                k-=numZeros;
                return numOnes-min(k,numNegOnes);
            }else{
                return numOnes;
            }
        }else{
            return k;
        }
    }
};
