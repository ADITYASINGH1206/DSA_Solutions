/**
 * Problem: Count Servers that Communicate (1267)
 * Link: https://leetcode.com/problems/count-servers-that-communicate/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans =0;
        vector<int>rows(251,0),cols(251,0);
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]&&(rows[i]>1||cols[j]>1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};
