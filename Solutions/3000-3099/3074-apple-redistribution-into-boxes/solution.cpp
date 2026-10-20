/**
 * Problem: Apple Redistribution into Boxes (3074)
 * Link: https://leetcode.com/problems/apple-redistribution-into-boxes/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = accumulate(apple.begin(),apple.end(),0);
        sort(capacity.rbegin(),capacity.rend());
        int ans = 0;
        int n = apple.size();
        int m = capacity.size();
        while(total>0){
            total -= capacity[ans++];
        }

        return ans;
    }
};
