/**
 * Problem: Maximum Bags With Full Capacity of Rocks (2279)
 * Link: https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int>diff(n);

        long long totaldiff=0;
        for(int i=0; i<n; i++){
            totaldiff+=(capacity[i]-rocks[i]);
        }

        if(totaldiff<=additionalRocks)
            return n;

        for(int i=0; i<n; i++){
            diff[i]=capacity[i]-rocks[i];
        }
        sort(diff.begin(), diff.end());

        for(int i=0; i<n; i++){
            if(additionalRocks>=diff[i]){
                additionalRocks-=diff[i];
                diff[i]=0;
            }
        }

        int cnt=0;

        for(int i=0; i<n; i++){
            if(diff[i]==0)
                cnt++;
        }

        return cnt;
    }
};
