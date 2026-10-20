/**
 * Problem: Crawler Log Folder (1598)
 * Link: https://leetcode.com/problems/crawler-log-folder/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        int n = logs.size();
        for(int i = 0;i<n;i++){
            if(logs[i] == "../"){
                if(ans>0) ans--;
            }
            else if(logs[i] == "./") continue;
            else{
                ans++;
            }
        }

        return ans;
    }
};
