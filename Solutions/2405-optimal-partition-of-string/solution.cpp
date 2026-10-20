/**
 * Problem: Optimal Partition of String (2405)
 * Link: https://leetcode.com/problems/optimal-partition-of-string/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        if(n == 1) return 1;
        int ans = 1;
        int l = 0;
        int r= 0;
        vector<int> freq(26,0);
        while(r<n){
            if(freq[s[r]-'a'] == 1){
                ans++;
                fill(freq.begin(), freq.end(), 0);
            }else{
                freq[s[r]-'a']++;
                r++;
            }
        }

        return ans;

    }
};
