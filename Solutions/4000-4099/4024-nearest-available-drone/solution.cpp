/**
 * Problem: Nearest Available Drone (4024)
 * Link: https://leetcode.com/problems/nearest-available-drone/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& t) {
        int minDist = INT_MAX;
        int idx = -1;

        for (int i = 0; i < drones.size(); i++) {
            int dist = abs(t[0] - drones[i][0])
                     + abs(t[1] - drones[i][1]);

            if (dist <= drones[i][2] && minDist > dist) {
                minDist = dist;
                idx = i;
            }
        }

        return idx;
    }
};
