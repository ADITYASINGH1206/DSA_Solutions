/**
 * Problem: Least Number of Unique Integers after K Removals (1481)
 * Link: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        int ans = 0;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            if(mp.find(arr[i]) == mp.end()) ans++;
            mp[arr[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto [key,value]:mp){
            v.push_back({key,value});
        }
        sort(v.begin(),v.end(),[](pair<int,int>&a,pair<int,int>&b){
            return a.second < b.second;
        });
        int i = 0;
        int sz = v.size();
        while(k>0 && i<sz){
            if(v[i].second>0){
                v[i].second--;
                if(v[i].second == 0){
                    i++;
                    ans--;
                }
                k--;
            }
            
        }
        return ans;
    }
};
