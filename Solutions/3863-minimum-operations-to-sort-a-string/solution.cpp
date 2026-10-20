/**
 * Problem: Minimum Operations to Sort a String (3863)
 * Link: https://leetcode.com/problems/minimum-operations-to-sort-a-string/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }
        
        if (n <= 2) {
            return -1;
        }
        
        char min_char = *min_element(s.begin(), s.end());
        char max_char = *max_element(s.begin(), s.end());
        
        if (s[0] == min_char || s[n - 1] == max_char) {
            return 1;
        }
        
        int max_count = count(s.begin(), s.end(), max_char);
        int min_count = count(s.begin(), s.end(), min_char);
        
        if (s[0] == max_char && max_count == 1 && 
            s[n - 1] == min_char && min_count == 1) {
            return 3;
        }
        
        return 2;
    }
};
