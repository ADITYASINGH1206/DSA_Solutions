/**
 * Problem: Minimum Capacity Box (3861)
 * Link: https://leetcode.com/problems/minimum-capacity-box/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ans = -1;
        int min_capacity = INT_MAX;
        
        for (int i = 0; i < capacity.size(); ++i) {
            if (capacity[i] >= itemSize) {
                if (capacity[i] < min_capacity) {
                    min_capacity = capacity[i];
                    ans = i;
                }
            }
        }
        
        return ans;
    }
};
