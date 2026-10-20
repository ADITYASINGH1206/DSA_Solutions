/**
 * Problem: Sum of All Odd Length Subarrays (1588)
 * Link: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if((j-i+1)%2!=0){
                    ans += accumulate(arr.begin()+i,arr.begin()+j+1,0);
                }
            }
        }
        return ans;

    }
};
