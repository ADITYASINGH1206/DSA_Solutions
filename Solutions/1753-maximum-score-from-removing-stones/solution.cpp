/**
 * Problem: Maximum Score From Removing Stones (1753)
 * Link: https://leetcode.com/problems/maximum-score-from-removing-stones/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(int a, int b, int c) 
    {
        int ans = 0;
        priority_queue<int>pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        while(!pq.empty() && pq.size()>1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop(); 
            if(x-1!=0) pq.push(x-1);
            if(y-1!=0) pq.push(y-1);
            ans++;
        }
        return ans;
    }
};
