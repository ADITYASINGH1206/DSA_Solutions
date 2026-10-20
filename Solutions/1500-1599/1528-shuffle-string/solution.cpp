/**
 * Problem: Shuffle String (1528)
 * Link: https://leetcode.com/problems/shuffle-string/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans = s;
        for(int i =0;i<s.size();i++){
            ans[indices[i]] = s[i];
        }
        return ans;
    }
};
