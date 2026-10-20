/**
 * Problem: Destination City (1436)
 * Link: https://leetcode.com/problems/destination-city/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> first;
        set<string> second;
        int n = paths.size();
        for(int i =0;i<n;i++){
            first.insert(paths[i][0]);
            second.insert(paths[i][1]);
        }

        for (const string& city : second) {
            if (first.find(city) == first.end()) {
                return city;
            }
        }
        return "";
        
    }
};
