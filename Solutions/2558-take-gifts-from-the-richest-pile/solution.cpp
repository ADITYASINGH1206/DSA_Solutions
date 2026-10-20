/**
 * Problem: Take Gifts From the Richest Pile (2558)
 * Link: https://leetcode.com/problems/take-gifts-from-the-richest-pile/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        for(int i = 0;i<k;i++){
            sort(gifts.rbegin(),gifts.rend());
            gifts[0] = floor(sqrt(gifts[0]));
        }
        long long ans = 0;
        for(int i = 0;i<n;i++){
            ans += gifts[i];
        }
        return ans;
    }
};
