/**
 * Problem: Snake in Matrix (3248)
 * Link: https://leetcode.com/problems/snake-in-matrix/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0 ,j=0;
        for(auto command :commands){
            if(command == "UP") i--;
            else if(command =="DOWN") i++;
            else if(command == "LEFT") j--;
            else j++;
        }
        int ans = (i*n) + j;
        return ans;
    }
};
