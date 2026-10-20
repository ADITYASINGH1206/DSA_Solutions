/**
 * Problem: Minimum Number of Pushes to Type Word II (3016)
 * Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> letterFreq(26, 0);
        for (char c : word) {
            letterFreq[c - 'a']++;
        }
        
        sort(letterFreq.rbegin(), letterFreq.rend());
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (letterFreq[i] == 0) break;
            if(i < 8) ans += letterFreq[i];
            else if(i<16) ans += 2*letterFreq[i];
            else if(i<24) ans += 3*letterFreq[i];
            else ans += 4*letterFreq[i];
        }
        
        return ans;
    }
};
