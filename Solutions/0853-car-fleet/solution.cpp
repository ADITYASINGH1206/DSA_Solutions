/**
 * Problem: Car Fleet (853)
 * Link: https://leetcode.com/problems/car-fleet/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        map<int, double> m;

        for (int i = 0; i < pos.size(); i++){
            m[-pos[i]] = (double)(target - pos[i]) / speed[i];
        }
        int ans = 0;
        double cur = 0;

        for (auto it : m) if (it.second > cur){
            cur = it.second;
            ans++;
        }
        return ans;
    }
};
