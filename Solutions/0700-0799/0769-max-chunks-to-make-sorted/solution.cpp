/**
 * Problem: Max Chunks To Make Sorted (769)
 * Link: https://leetcode.com/problems/max-chunks-to-make-sorted/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int ans=0, diff=0;
        for(int i=0; i<n; i++){
            diff+=arr[i]-i;
            if(diff==0) ans++;
        }
        return ans;
    }
};
