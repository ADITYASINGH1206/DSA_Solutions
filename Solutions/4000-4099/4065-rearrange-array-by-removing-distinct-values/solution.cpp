/**
 * Problem: Rearrange Array by Removing Distinct Values (4065)
 * Link: https://leetcode.com/problems/rearrange-array-by-removing-distinct-values/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num : nums) {
            mp[num]++;
        }
        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.first > b.first; 
        };
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        
        for(auto [key, value] : mp) {
            pq.push({key, value});
        }
        
        vector<int> ans;
        
        while(!pq.empty()) {
            vector<pair<int,int>> next_round;
            while(!pq.empty()) {
                auto [key, value] = pq.top();
                pq.pop();
                ans.push_back(key);
                value--;
                if(value > 0) {
                    next_round.push_back({key, value});
                }
            }
            for(auto& p : next_round) {
                pq.push(p);
            }
        }
        
        return ans;
    }
};
