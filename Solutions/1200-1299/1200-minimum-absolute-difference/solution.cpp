/**
 * Problem: Minimum Absolute Difference (1200)
 * Link: https://leetcode.com/problems/minimum-absolute-difference/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int mi =arr[1]-arr[0];
        for(int i=1;i<arr.size();i++){
            mi = min(mi,abs(arr[i-1]-arr[i]));
        }
        for(int i =1;i<arr.size();i++){
            if(abs(arr[i]-arr[i-1]) ==mi){
                vector<int> el = {arr[i-1],arr[i]};
                ans.push_back(el);
            }
        }
        return ans;
    }
};
