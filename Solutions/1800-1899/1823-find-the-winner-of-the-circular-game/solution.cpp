/**
 * Problem: Find the Winner of the Circular Game (1823)
 * Link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++)
        {
            q.push(i);
        }
        while(q.size()>1)
        {
            int temp=k-1;
            while(temp--)
            {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};
