/**
 * Problem: Minimum Amount of Time to Collect Garbage (2391)
 * Link: https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int maxi_G = 0;
        int maxi_P = 0;
        int maxi_M = 0;
        int ans = 0;
        for(int i = 0 ;i < garbage.size();i++){
            for(char gar : garbage[i]){
                if(gar == 'G') maxi_G = max(maxi_G,i);
                else if(gar == 'M') maxi_M = max(maxi_M,i);
                else maxi_P = max(maxi_P,i);
            }
        }
        for(int i =0;i<=maxi_G;i++){
            if(i) ans += travel[i-1];
            for(char gar : garbage[i]){
                if(gar == 'G') ans++;
            }
        }
        for(int i =0;i<=maxi_P;i++){
            if(i) ans += travel[i-1];
            for(char gar : garbage[i]){
                if(gar == 'P') ans++;
            }
        }
        for(int i =0;i<=maxi_M;i++){
            if(i) ans += travel[i-1];
            for(char gar : garbage[i]){
                if(gar == 'M') ans++;
            }
        }
        return ans;
    }
};
