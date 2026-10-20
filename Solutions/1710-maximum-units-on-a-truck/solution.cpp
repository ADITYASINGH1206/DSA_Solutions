/**
 * Problem: Maximum Units on a Truck (1710)
 * Link: https://leetcode.com/problems/maximum-units-on-a-truck/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        int ans = 0;
        sort(boxTypes.begin(),boxTypes.end(),[](const vector<int>& a, const vector<int>& b){
            return a[1] > b[1];
        });
        int i = 0;
        while(i<n){
            while(boxTypes[i][0]>0){
                ans+= boxTypes[i][1];
                boxTypes[i][0]--;
                truckSize--;
                if(truckSize == 0) return ans;
            }
            i++;

        }
        return ans;
    }
};
