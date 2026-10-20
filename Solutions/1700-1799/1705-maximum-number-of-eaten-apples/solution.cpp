/**
 * Problem: Maximum Number of Eaten Apples (1705)
 * Link: https://leetcode.com/problems/maximum-number-of-eaten-apples/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        int n = apples.size();
        int day = 0;
        int eaten = 0;

        while (day < n || !pq.empty()) {
            if (day < n && apples[day] > 0) {
                pq.push({day + days[day], apples[day]});
            }

            while (!pq.empty() && pq.top().first <= day) {
                pq.pop();
            }
            if (!pq.empty()) {
                auto p = pq.top();
                pq.pop();

                p.second--;
                eaten++;

                if (p.second > 0)
                    pq.push(p);
            }

            day++;
        }

        return eaten;
    }
};
