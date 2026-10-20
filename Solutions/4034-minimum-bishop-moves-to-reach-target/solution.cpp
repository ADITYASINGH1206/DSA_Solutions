/**
 * Problem: Minimum Bishop Moves to Reach Target (4034)
 * Link: https://leetcode.com/problems/minimum-bishop-moves-to-reach-target/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        if(source[0] == target[0] && source[1] == target[1]) return 0;

        if((source[0] + source[1])%2 != (target[0] + target[1])%2)return -1;


        if(abs(source[0]-target[0]) == abs(source[1]-target[1])) return 1;

        else return 2;
    }
};
