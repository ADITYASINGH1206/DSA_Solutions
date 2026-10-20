/**
 * Problem: Minimum Operations to Make a Rotated Palindrome I (4021)
 * Link: https://leetcode.com/problems/minimum-operations-to-make-a-rotated-palindrome-i/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length(); 
        
        int ans = INT_MAX;
        string doubled = s + s;
        
        for (int k = 0; k < n; ++k) {
            int cur = k;
            int left = k;
            int right = k + n - 1;
            while (left < right) {
                int diff = abs(doubled[left] - doubled[right]);
                cur += min(diff, 26 - diff);
                left++;
                right--;
            }
            if (cur < ans) {
                ans = cur;
            }
        }
        
        return ans;
    }
};
