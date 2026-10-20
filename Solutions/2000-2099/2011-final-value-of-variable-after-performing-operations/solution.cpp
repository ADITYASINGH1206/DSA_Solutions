/**
 * Problem: Final Value of Variable After Performing Operations (2011)
 * Link: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(int i=0;i < operations.size() ;  i++){
            if((operations[i] =="++X")|| (operations[i] =="X++")){
                x+=1;
            }
            else{
                x-=1;
            }
        }
        return x;
        
    }
};
