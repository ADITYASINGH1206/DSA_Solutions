/**
 * Problem: Unique 3-Digit Even Numbers (3483)
 * Link: https://leetcode.com/problems/unique-3-digit-even-numbers/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& digits, vector<int>& vis, int& ans, int num, int dig) {
        if (dig == 3) {
            if (num % 2 == 0) ans++;
            return;
        }

        for (int i = 0; i < digits.size(); i++) {
            if (vis[i] == 1) continue; 
            if (dig == 0 && digits[i] == 0) continue;
            if (i > 0 && digits[i] == digits[i-1] && !vis[i-1]) continue;
            vis[i] = 1;
            backtrack(digits, vis, ans, num * 10 + digits[i], dig + 1);
            vis[i] = 0;
        }
    }
    
    int totalNumbers(vector<int>& digits) {
        int ans = 0;
        vector<int> vis(digits.size(), 0);
        sort(digits.begin(), digits.end());
        backtrack(digits, vis, ans, 0, 0);
        return ans;
    }
};
