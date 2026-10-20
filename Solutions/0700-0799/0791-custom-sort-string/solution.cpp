/**
 * Problem: Custom Sort String (791)
 * Link: https://leetcode.com/problems/custom-sort-string/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        int n = s.size();
        int m = order.size();
        unordered_map<char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
        string ans = "";
        for(char c: order){
            if(mp[c]){
                while(mp[c]>0){
                    ans += c;
                    mp[c]--;
                }
            }
        }
        for(char c: s){
            if(mp[c]){
                ans+= c;
                mp[c]--;
            }
        }


        return ans;
    }
};
