/**
 * Problem: Replace Elements with Greatest Element on Right Side (1299)
 * Link: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        int maxi=-1;
        for(int i=n-1;i>=0;i--){
            swap(arr[i],maxi);
            maxi=max(maxi,arr[i]);
        }
        return arr;
    }
};
