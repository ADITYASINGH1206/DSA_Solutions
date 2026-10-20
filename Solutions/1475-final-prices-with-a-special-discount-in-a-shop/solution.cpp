/**
 * Problem: Final Prices With a Special Discount in a Shop (1475)
 * Link: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st; 
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                prices[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        
        return prices;
    }
};
