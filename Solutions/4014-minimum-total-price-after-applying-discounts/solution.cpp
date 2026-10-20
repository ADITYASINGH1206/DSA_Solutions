/**
 * Problem: Minimum Total Price After Applying Discounts (4014)
 * Link: https://leetcode.com/problems/minimum-total-price-after-applying-discounts/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        double ans = 0.0;
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());
        int n = prices.size();
        int m = discounts.size();
        for(int i = 0;i<n;i++){
            if(i<m) ans+= (double)(prices[i]*(100-discounts[i]))/100;
            else ans+= prices[i];
        }
        return ans;
    }
};
