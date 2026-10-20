/**
 * Problem: Minimum Amount of Time to Fill Cups (2335)
 * Link: https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fillCups(vector<int>& amount) {
        int n = amount.size();
        int ans = 0;
        priority_queue<int> pq;
        if(amount[0]>0)pq.push(amount[0]);
        if(amount[1]>0)pq.push(amount[1]);
        if(amount[2]>0)pq.push(amount[2]);
        while(!pq.empty()){
            int top1 = pq.top();
            pq.pop();
            int top2 = 0;
            if(!pq.empty()){
                top2 = pq.top();
                pq.pop();
            }
            if(--top1>0)pq.push(top1);
            if(--top2>0)pq.push(top2);
            ans++;

        }
        return ans;
    }
};
