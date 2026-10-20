/**
 * Problem: Merge Similar Items (2363)
 * Link: https://leetcode.com/problems/merge-similar-items/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> ans;
        sort(items1.begin(), items1.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0]; 
        });
        sort(items2.begin(), items2.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0]; 
        });
        
        int m = items1.size();
        int n = items2.size();
        int i = 0,j=0;
        while(i<m && j<n){
            if(items1[i][0] == items2[j][0]) {
                ans.push_back({items1[i][0],items1[i][1]+items2[j][1]});
                i++,j++;
            }
            else if(items1[i][0] > items2[j][0]){
                ans.push_back({items2[j][0],items2[j][1]});
                j++;
            }else{
                ans.push_back({items1[i][0],items1[i][1]});
                i++;
            }
        }
        while(i<m){
            ans.push_back({items1[i][0],items1[i][1]});
            i++;
        }
        while(j<n){
            ans.push_back({items2[j][0],items2[j][1]});
            j++;
        }

        return ans;
    }
};
