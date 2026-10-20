/**
 * Problem: Minimum Cost to Make Two Binary Strings Equal (3800)
 * Link: https://leetcode.com/problems/minimum-cost-to-make-two-binary-strings-equal/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        long long c01 = 0;
        long long c10 = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '0' && t[i] == '1') {
                c01++;
            } else if (s[i] == '1' && t[i] == '0') {
                c10++;
            }
        }
        
        long long cost_diff = min((long long)swapCost, 2LL * flipCost);
        long long cost_same = min((long long)(crossCost + swapCost), 2LL * flipCost);
        
        long long diff_pairs = min(c01, c10);

        long long remainder = abs(c01 - c10);
        long long same_pairs = remainder / 2;
        long long singles = remainder % 2; 

        long long totalCost = (diff_pairs * cost_diff) + 
                              (same_pairs * cost_same) + 
                              (singles * flipCost);
                              
        return totalCost;
    }
};
