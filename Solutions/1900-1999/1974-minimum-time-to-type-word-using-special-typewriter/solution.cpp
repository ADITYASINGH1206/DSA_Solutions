/**
 * Problem: Minimum Time to Type Word Using Special Typewriter (1974)
 * Link: https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToType(string word) {
        int n = word.size();
        int ans = 0;
        int cur = 0; 
        for(int i = 0; i < n; i++){
            int target = word[i] - 'a';
            int diff = abs(cur - target);
            int min_move = min(diff, 26 - diff);
            ans += min_move + 1;
            cur = target;
        }
        
        return ans;
    }
};
