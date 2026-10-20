/**
 * Problem: Widest Possible Fence (4007)
 * Link: https://leetcode.com/problems/widest-possible-fence/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int, int> freq;
        for (int p : planks) {
            freq[p]++;
        }
        
        unordered_map<int, int> mp;
        vector<int> uniques;
        for (auto& pair : freq) {
            uniques.push_back(pair.first);
        }
        
        int n = uniques.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            int h1 = uniques[i];
            mp[h1] += freq[h1];
            mp[h1 * 2] += freq[h1] / 2;
            for (int j = i + 1; j < n; j++) {
                int h2 = uniques[j];
                mp[h1 + h2] += min(freq[h1], freq[h2]);
            }
        }
        
        for (auto& pair : mp) {
            ans = max(ans, pair.second);
        }
        
        return ans;
    }
};
