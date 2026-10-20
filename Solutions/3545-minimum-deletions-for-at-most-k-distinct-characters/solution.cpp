/**
 * Problem: Minimum Deletions for At Most K Distinct Characters (3545)
 * Link: https://leetcode.com/problems/minimum-deletions-for-at-most-k-distinct-characters/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char, int> mp;
        for(char c : s) {
            mp[c]++;
        }
        vector<int> freqs;
        for(auto& pair : mp) {
            freqs.push_back(pair.second);
        }
        sort(freqs.begin(), freqs.end(), greater<int>());
        int ans = 0;
        for(int i = k; i < freqs.size(); i++) {
            ans += freqs[i];
        }

        return ans;
    }
};
