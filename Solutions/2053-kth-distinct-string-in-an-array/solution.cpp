/**
 * Problem: Kth Distinct String in an Array (2053)
 * Link: https://leetcode.com/problems/kth-distinct-string-in-an-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
        int n = arr.size();
        for(string s: arr){
            mp[s]++;
        }
        int c= 0;
        for(string s : arr){
            if(mp[s] == 1){
                c++;
                if(c == k) return s;
            }
        }
        return "";
    }
};
