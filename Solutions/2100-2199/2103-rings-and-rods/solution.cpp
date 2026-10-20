/**
 * Problem: Rings and Rods (2103)
 * Link: https://leetcode.com/problems/rings-and-rods/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPoints(string rings) {
        vector<vector<bool>> mp(10, vector<bool>(3, false));
        int n = rings.size();
        for(int i = 0 ;i < n;i+=2){

            int idx = rings[i+1] - '0';

            if(rings[i] == 'R') mp[idx][0] = true;
            else if(rings[i] == 'G') mp[idx][1] = true;
            else if(rings[i] == 'B')mp[idx][2] = true;
        }
        int ans = 0;
        for(int i =0;i<10;i++) {
            if(mp[i][0] && mp[i][1] && mp[i][2]) {
                ans++;
            }
        }
        return ans;
    }
};
