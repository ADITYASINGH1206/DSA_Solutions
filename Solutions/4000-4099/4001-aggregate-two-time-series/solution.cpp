/**
 * Problem: Aggregate Two Time Series (4001)
 * Link: https://leetcode.com/problems/aggregate-two-time-series/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>>ans;
        int m = series1.size();
        int n = series2.size();
        int i =0 ,j=0;
        while(i<m && j<n){
            int sum = 0;
            int time = 0;
            if(series1[i][0]==series2[j][0]){
                time = series1[i][0];
                sum=series1[i][1]+series2[j][1];
                i++;
                j++;
            }else if(series1[i][0]<series2[j][0]){
                time = series1[i][0];
                sum=series1[i][1] + series2[j][1];
                i++;
            }else{
                time = series2[j][0];
                sum=series2[j][1]+series1[i][1];
                j++;
            }
            ans.push_back({time,sum});
        }
        while(i<m){
            ans.push_back({series1[i][0],series1[i++][1]});
        }
        while(j<n){
            ans.push_back({series2[j][0],series2[j++][1]});
        }
        return ans;
    }
};
