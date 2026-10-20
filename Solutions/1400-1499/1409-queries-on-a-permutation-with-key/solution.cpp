/**
 * Problem: Queries on a Permutation With Key (1409)
 * Link: https://leetcode.com/problems/queries-on-a-permutation-with-key/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        vector<int> permutes(m);
        vector<int> ans;
        for(int i = 0;i<m;i++){
            permutes[i] = i+1;
        }
        permute(permutes,queries,0,ans);
        return ans;

    }
    void permute(vector<int>& cur,vector<int>& queries,int index,vector<int>& ans){
        if(index == queries.size()) return;
        vector<int> next;
        next.push_back(queries[index]);
        for(int i = 0;i<cur.size();i++){
            if(cur[i] == queries[index]){
                ans.push_back(i);
                continue;
            } 
            next.push_back(cur[i]);
        }
        permute(next,queries,index+1,ans);

        return;
    }

};
