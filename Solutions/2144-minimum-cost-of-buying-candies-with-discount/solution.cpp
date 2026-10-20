/**
 * Problem: Minimum Cost of Buying Candies With Discount (2144)
 * Link: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int ans = 0;
        for (int i = 0; i < cost.size(); i += 3) {
            ans += cost[i];
            if (i < cost.size() - 1) {
                ans += cost[i + 1];
            }
        }
        return ans;
    }
};
