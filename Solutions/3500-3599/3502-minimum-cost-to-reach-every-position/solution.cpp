/**
 * Problem: Minimum Cost to Reach Every Position (3502)
 * Link: https://leetcode.com/problems/minimum-cost-to-reach-every-position/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> ans;
        int n = cost.size();
        ans.push_back(cost[0]);
        for(int i = 1;i<n;i++){
            ans.push_back(min(ans.back(),cost[i]));

        }
        return ans;
    }
};
