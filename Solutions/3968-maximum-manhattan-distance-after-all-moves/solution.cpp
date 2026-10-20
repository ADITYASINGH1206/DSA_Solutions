/**
 * Problem: Maximum Manhattan Distance After All Moves (3968)
 * Link: https://leetcode.com/problems/maximum-manhattan-distance-after-all-moves/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(string moves) {
        int ans = 0;
        int xf = 0;
        int yf = 0;
        for(char c:moves){
            if(c == 'U')yf++;
            else if(c == 'D')yf--;
            else if(c == 'L')xf--;
            else if(c == 'R')xf++;
            else{
                ans++;
            }
        }
        ans += abs(xf) + abs(yf);

        return ans;
    }
};
