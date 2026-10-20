/**
 * Problem: Maximum Number of Integers to Choose From a Range I (2554)
 * Link: https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int a=banned.size();
        unordered_map<int,int> x;
        for(int i=0;i<a;i++){
            x[banned[i]]=1;
        }
        int sum=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(x[i]!=0) continue;
            sum+=i;
            if(sum>maxSum) break;
            cnt++;
        }
        return cnt;
    }
};
