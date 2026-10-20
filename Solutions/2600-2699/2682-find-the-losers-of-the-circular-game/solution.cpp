/**
 * Problem: Find the Losers of the Circular Game (2682)
 * Link: https://leetcode.com/problems/find-the-losers-of-the-circular-game/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::vector<int> circularGameLosers(int n, int k) {
        vector<bool> received(n, false);
        
        int curr = 0;
        int step = 1; 
        
        while (!received[curr]) {
            received[curr] = true;             
            curr = (curr + step * k) % n;      
            step++;                            
        }
        

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!received[i]) {
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};
