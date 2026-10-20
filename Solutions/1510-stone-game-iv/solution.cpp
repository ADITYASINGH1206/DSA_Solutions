/**
 * Problem: Stone Game IV (1510)
 * Link: https://leetcode.com/problems/stone-game-iv/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MAX = 100000;
    inline static bitset<MAX + 1> dp;

    inline static bool init = []() {
        for (int i = 0; i <= MAX; i++) {
            if (dp.test(i)) continue;
            for (int j = 1; j * j <= MAX - i; j++)
                dp.set(i + j * j);
        }
        
        return false;
    }();

    bool winnerSquareGame(int n) { return dp.test(n); }
};
