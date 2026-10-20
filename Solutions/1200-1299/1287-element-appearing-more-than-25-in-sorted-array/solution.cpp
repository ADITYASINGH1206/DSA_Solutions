/**
 * Problem: Element Appearing More Than 25% In Sorted Array (1287)
 * Link: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int ans= arr[0];
        int count = 0;
        for(int i =0;i<arr.size();i++){
            if(arr[i] == ans){
                count++;
            }else{
                count =1;
                ans=arr[i];
            }
            if(count>(n/4)){
                return ans;
            }
        }
        return ans;
    }
};
