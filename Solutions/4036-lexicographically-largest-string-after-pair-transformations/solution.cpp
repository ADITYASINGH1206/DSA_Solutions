/**
 * Problem: Lexicographically Largest String After Pair Transformations (4036)
 * Link: https://leetcode.com/problems/lexicographically-largest-string-after-pair-transformations/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        
        for (int x : nums) {
            vector<int> counts(26, 0);
            for (int i = 0; i < 25; ++i) {
                counts[i] = x % 2; 
                x = x / 2;         
            }
            counts[25] = x; 
            
            
            string s = "";
            for (int i = 25; i >= 0; --i) {
                if (counts[i] > 0) {
                    s.append(counts[i], (char)('a' + i));
                }
            }
            
            ans.push_back(s);
        }
        
        return ans;
    }
};
