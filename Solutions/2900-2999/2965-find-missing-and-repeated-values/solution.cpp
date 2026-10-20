/**
 * Problem: Find Missing and Repeated Values (2965)
 * Link: https://leetcode.com/problems/find-missing-and-repeated-values/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freq(n*n+1,0);
        vector<int> ans(2,0);
        for(int i = 0;i<n;i++){
            for(int j =0;j<n;j++){
                int x = grid[i][j];
                freq[x]++;
                if(freq[x] == 2) ans[0] =x;
            }
        }
        for(int i =0;i<freq.size();i++){
            if(freq[i] == 0) ans[1] = i;
        }
        return ans;

    }
};
