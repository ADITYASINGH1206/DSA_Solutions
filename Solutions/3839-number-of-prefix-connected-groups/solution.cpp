/**
 * Problem: Number of Prefix Connected Groups (3839)
 * Link: https://leetcode.com/problems/number-of-prefix-connected-groups/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> prefixCounts;
        for(const string& word : words) {
            if(word.length() >= k) {
                string prefix = word.substr(0, k);
                prefixCounts[prefix]++;
            }
        }
        int groupCount = 0;
        for(auto it : prefixCounts) {
            if(it.second >= 2) {
                groupCount++;
            }
        }
        
        return groupCount;
    }
};
