/**
 * Problem: Count Common Words With One Occurrence (2085)
 * Link: https://leetcode.com/problems/count-common-words-with-one-occurrence/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;
        
        for (const string& s : words1) mp1[s]++;
        for (const string& s : words2) mp2[s]++;

        int ans = 0;

        for (auto const& [word, count] : mp1) {
            if (count == 1 && mp2[word] == 1) {
                ans++;
            }
        }
        
        return ans;
    }
};
