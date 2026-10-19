/**
 * Problem: Minimum Cost to Move Chips to The Same Position (1217)
 * Link: https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n = position.size();
        if(n==1) return 0;
        int evens = 0;
        int odds = 0;
        for(int i = 0;i<n;i++){
            if(position[i]%2 ==0) evens++;
            else odds++;
        }
        if(odds == 0 || evens == 0) return 0;
        return min(evens,odds);
    }
};
