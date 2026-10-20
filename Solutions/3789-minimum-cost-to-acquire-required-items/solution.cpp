/**
 * Problem: Minimum Cost to Acquire Required Items (3789)
 * Link: https://leetcode.com/problems/minimum-cost-to-acquire-required-items/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;

        if (cost1 + cost2 > costBoth) {
            long long pairs = min(need1, need2);
            ans += pairs * costBoth;
            need1 -= pairs;
            need2 -= pairs;

            if (need1 > 0) {
                long long bestCost1 = min(cost1, costBoth);
                ans += (long long)need1 * bestCost1;
            }
            
            if (need2 > 0) {
                long long bestCost2 = min(cost2, costBoth);
                ans += (long long)need2 * bestCost2;
            }
        } 
        else {
            ans = ((long long)cost1 * need1) + ((long long)cost2 * need2);
        }
        
        return ans;
    }
};
