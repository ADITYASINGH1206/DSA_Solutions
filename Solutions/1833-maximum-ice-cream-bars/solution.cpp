/**
 * Problem: Maximum Ice Cream Bars (1833)
 * Link: https://leetcode.com/problems/maximum-ice-cream-bars/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans=0;
        for(int x:costs){
            if(x>coins)break;
            ans++;
            coins-=x;
        }
        return ans;
    }
};
