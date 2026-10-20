/**
 * Problem: Find Closest Person (3516)
 * Link: https://leetcode.com/problems/find-closest-person/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int ans = 0;
        if(abs(x-z) < abs(y-z)){
            ans = 1;
        } 
        else if(abs(x-z) > abs(y-z)){
            ans = 2;
        }
        return ans;
    }
};
