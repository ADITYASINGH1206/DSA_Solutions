/**
 * Problem: Minimize String Length (2716)
 * Link: https://leetcode.com/problems/minimize-string-length/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizedStringLength(string s) {
        int ans = 0;
        int n = s.size();
        unordered_map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        for(auto [key,value] : mp){
            if(value > 1){
                ans += value-1;
            }
        }
        ans = n-ans;
        return ans;
    }
};
