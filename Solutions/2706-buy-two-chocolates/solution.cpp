/**
 * Problem: Buy Two Chocolates (2706)
 * Link: https://leetcode.com/problems/buy-two-chocolates/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int m = money;
        m = m-prices[0]-prices[1];
        return m <0 ? money : m;
    }
};
