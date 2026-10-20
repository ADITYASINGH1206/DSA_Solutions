/**
 * Problem: Find Minimum Operations to Make All Elements Divisible by Three (3190)
 * Link: https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(int i :nums){
            if((i%3==1)||(i%3==2)){
                ans++;
            }
        }
        return ans;    
    }
};
