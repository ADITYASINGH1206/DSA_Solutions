/**
 * Problem: Alternating Groups I (3206)
 * Link: https://leetcode.com/problems/alternating-groups-i/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            int l = 0;
            int r = 0;
            if(i == 0){
                l = n-1;
                r = i+1;
            }else if(i == n-1){
                l = i-1;
                r = 0;
            }else{
                l = i-1;
                r = i+1;
            }
            if(colors[i] != colors[l] && colors[i] != colors[r]){
                ans++;
            }
        }
        return ans;
    }
};
