/**
 * Problem: Elevator Requests I (4020)
 * Link: https://leetcode.com/problems/elevator-requests-i/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int ans = 0;
        int sz = requests.size();
        int cur = 0;
        for(int i = 0;i<sz;i++){
            ans += abs(cur-requests[i]);
            cur = requests[i];
        }

        return ans;
    }
};
