/**
 * Problem: Count Valid Prefixes (4006)
 * Link: https://leetcode.com/problems/count-valid-prefixes/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidPrefixes(string s) {
        int ans = 0;
        int zero = 0;
        int one = 0;
        
        for (char c : s) {
            if (c == '0') {
                zero++;
            } else {
                one++;
            }
            
            if (abs(zero - one) <= 1) {
                ans++;
            }
        }
        
        return ans;
    }
};
