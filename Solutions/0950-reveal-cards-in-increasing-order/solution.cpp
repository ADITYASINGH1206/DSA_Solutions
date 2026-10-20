/**
 * Problem: Reveal Cards In Increasing Order (950)
 * Link: https://leetcode.com/problems/reveal-cards-in-increasing-order/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n,-1);
        queue<int> q;
        sort(deck.begin(),deck.end());
        vector<int> indices;
        for(int i = 0;i<n;i++){
            q.push(i);
        }
        while(!q.empty()){
            int top = q.front();
            indices.push_back(top);
            q.pop();
            if(!q.empty()){
                int next = q.front();
                q.push(next);
                q.pop();
            }
        }
        for(int i = 0;i<n;i++){
            ans[indices[i]] = deck[i];
        }
        return ans;
    }
};
